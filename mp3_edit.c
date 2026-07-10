#include "mp3_header.h"
#include<stdlib.h>
#include<string.h>
void edit(struct MP3 *mp3)
{
    int choice;
    char *edit_tag = NULL;
    if(strcmp(mp3->edit_option, "-t") == 0)
    {
        edit_tag = "TIT2";
    }

    else if(strcmp(mp3->edit_option, "-a") == 0)
    {
        edit_tag = "TPE1";
    }

    else if(strcmp(mp3->edit_option, "-A") == 0)
    {
        edit_tag = "TALB";
    }

    else if(strcmp(mp3->edit_option, "-y") == 0)
    {
        edit_tag = "TYER";
    }

    else if(strcmp(mp3->edit_option, "-m") == 0)
    {
        edit_tag = "TCON";
    }

    else if(strcmp(mp3->edit_option, "-c") == 0)
    {
        edit_tag = "TCOM";
    }

    else
    {
        printf("Invalid edit option\n");
        return;
    }
    printf("Selected tag: %s\n", edit_tag);

    mp3->org_mp3_fptr = fopen(mp3->mp3_filename,"rb");
    mp3->dup_mp3_fptr = fopen("temp.mp3","wb");

    if(!mp3->org_mp3_fptr || !mp3->dup_mp3_fptr)
    {
        perror("File error");
        return;
    }

    unsigned char header[10];
    fread(header,1,10,mp3->org_mp3_fptr);
    fwrite(header,1,10,mp3->dup_mp3_fptr);

    char tag[5];
    int size;
    char flag[2];

    while(1)
    {
        if(fread(tag,1,4,mp3->org_mp3_fptr) != 4)//read 4 bytes of tag
        {
            break;
        }

        tag[4] = '\0';

        // End condition
        if(tag[0] == 0)
        {
            break;
        }

        fread(&size,1,4,mp3->org_mp3_fptr);//read 4 bytes of size
        toggle_endianess(mp3, &size);

        fread(flag,1,2,mp3->org_mp3_fptr);//read 2 bytes of flag

        if(strcmp(tag, edit_tag) == 0)
        {
            int old_size = size;

            char new_data[100];
            printf("Enter new value: ");
            scanf(" %[^\n]", new_data);

            int new_size = strlen(new_data) + 1;

            printf("Old size: %d\n", old_size);
            printf("New size: %d\n", new_size);

            int temp_size = new_size;
            toggle_endianess(mp3, &temp_size);

            fwrite(tag,1,4,mp3->dup_mp3_fptr);//write 4 bytes of tag
            fwrite(&temp_size,1,4,mp3->dup_mp3_fptr);//write 4 bytes of size
            fwrite(flag,1,2,mp3->dup_mp3_fptr);//write 2 bytes of flag

            fputc(0, mp3->dup_mp3_fptr);
            fwrite(new_data,1,strlen(new_data),mp3->dup_mp3_fptr);

            fseek(mp3->org_mp3_fptr, old_size, SEEK_CUR);
        }
        else
        {
            fwrite(tag,1,4,mp3->dup_mp3_fptr);

            int temp_size = size;
            toggle_endianess(mp3, &temp_size);
            fwrite(&temp_size,1,4,mp3->dup_mp3_fptr);

            fwrite(flag,1,2,mp3->dup_mp3_fptr);

            char *buffer = malloc(size);
            if(buffer == NULL)
            {
                printf("Memory error\n");
                return;
            }

            fread(buffer,1,size,mp3->org_mp3_fptr);
            fwrite(buffer,1,size,mp3->dup_mp3_fptr);
            free(buffer);
        }
    }

    // Copy remaining audio
    char buffer[1024];
    size_t bytes;

    while((bytes = fread(buffer, 1, sizeof(buffer), mp3->org_mp3_fptr)) > 0)
    {
        fwrite(buffer, 1, bytes, mp3->dup_mp3_fptr);
    }

    fclose(mp3->org_mp3_fptr);
    fclose(mp3->dup_mp3_fptr);

    remove(mp3->mp3_filename);
    rename("temp.mp3",mp3->mp3_filename);

    printf("Tag edited successfully!\n");

}

