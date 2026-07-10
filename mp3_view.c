#include "mp3_header.h"
#include<stdlib.h>
#include<string.h>
//extern int g_content_size;
void tag_to_name(char *tag)
{
    printf("------------------------------------------------------------------------------\n");
    if(strcmp(tag, "TIT2") == 0)
    {
        printf("Title : ");
    }
    else if(strcmp(tag, "TPE1") == 0)
    {
        printf("Artist : ");
    }
    else if(strcmp(tag, "TALB") == 0)
    {
        printf("Album : ");
    }
    else if(strcmp(tag, "TYER") == 0)
    {
        printf("Year : ");
    }
    else if(strcmp(tag, "TCON") == 0)
    {
        printf("Content Type : ");
    }
    else if(strcmp(tag, "TCOM") == 0)
    {
        printf("Comment : ");
    }
    else
    {
        printf("Unknown (%s) : ", tag);
    }    
}
void print_tag_data(struct MP3 *mp3, int content_size)
{
    
    if(content_size <= 0 || content_size > 10000)
    {
        printf("Invalid content size\n");
        return;
    }

    char data[10001];   // fixed buffer (string style)

    if(fread(data, 1, content_size, mp3->org_mp3_fptr) != content_size)
    {
        printf("Error reading data\n");
        return;
    }

    data[content_size] = '\0';   // make it string

    // skip encoding byte (data[0])(turns information into coded format)
    printf("%s\n", data + 1);

    
}

void view(struct MP3 *mp3)
{
    mp3->org_mp3_fptr = fopen(mp3->mp3_filename,"rb");

    if(!mp3->org_mp3_fptr)
    {
        perror("ERROR");
        return;
    }
    
    char mp3_identifier[] = "ID3";
    char buffer[4];
    if(fread(buffer,1,3,mp3->org_mp3_fptr) != 3)
    {
        printf("Error reading file\n");
        fclose(mp3->org_mp3_fptr);
        return;
    }
    buffer[3] = '\0';
    //compare id3
    if(strcmp(buffer,mp3_identifier)!=0)
    {
        printf("Not a valid MP3 file with ID3 tag\n");
        fclose(mp3->org_mp3_fptr);
        return;
    }
   
    fseek(mp3->org_mp3_fptr,7,SEEK_CUR);//skip 7 bytes
    char tag[5];
    int content_size;
    //Loop through all frames
    while(1)
    {
        // Read tag
        if(fread(tag,1,4,mp3->org_mp3_fptr) != 4)
        {
            break;
        }

        tag[4] = '\0';

        // Stop if padding
        if(tag[0] == 0)
        {
            break;
        }

        // Read size
        if(fread(&content_size,1,4,mp3->org_mp3_fptr) != 4)
        {
            printf("Error reading size\n");
            break;
        }
        
        // Convert endian
        toggle_endianess(mp3,&content_size);

        //printf("Actual content_size = %d\n", content_size);

        // Skip flags first
        fseek(mp3->org_mp3_fptr, 2, SEEK_CUR);

        // THEN validate
        if(content_size <= 0 || content_size > 10000)
        {
            printf("Invalid content size, skipping...\n");
            continue;
        }

        // Print tag name
        tag_to_name(tag);

        // Print tag data
        print_tag_data(mp3,content_size);
    }

    fclose(mp3->org_mp3_fptr);
}


