#include "mp3_header.h"
//int g_content_size = 0;
int validate_cla(int argc, char *argv[], struct MP3 *mp3)
{
    if( argc == 1 )
    {
		printf("------------------------------------------------------------------------------\n");
		printf("ERROR: ./a.out : INVALID ARGUMENTS\n");
		printf("USAGE : To view please pass like: ./a.out -v mp3filename\n");
		printf("To edit please pass like: ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\n");
		printf("To get help pass like : ./a.out --help\n");
		printf("------------------------------------------------------------------------------\n");
		return 0;
    }

    if( (strcmp(argv[1], "--help") == 0) )
    {
		printf("------------------------------->HELP<-----------------------------------------\n");
		printf("1. -v -> to view mp3 file contents\n");
		printf("2. -e -> to edit mp3 file contents\n");
		printf("\t\t2.1. -t -> to edit song title\n");
		printf("\t\t2.2. -a -> to edit artist name\n");
		printf("\t\t2.3. -A -> to edit album name\n");
		printf("\t\t2.4. -y -> to edit year\n");
		printf("\t\t2.5. -m -> to edit content\n");
		printf("\t\t2.6. -c -> to edit comment\n");
		printf("------------------------------------------------------------------------------\n");
		return 0; 
    }

    if(!strcmp(argv[1], "-v"))
    {
	// Do the necessary validation
		if(argc != 3)
        {
            printf("ERROR : Invalid arguments for view\n");
            return 0;
        }

        mp3->mp3_filename = argv[2];

		return VIEW;
    }
    
    if(!strcmp(argv[1], "-e"))
    {
	// Do the necessary validation
		if(argc != 5)
        {
            printf("ERROR : Invalid arguments for edit\n");
            return 0;
        }

        mp3->edit_option = argv[2];
        mp3->new_text = argv[3];
        mp3->mp3_filename = argv[4];


		return EDIT;
    }
	printf("ERROR : Invalid option\n");
	return 0;

}


void toggle_endianess(struct MP3 *mp3, int *size)
{
	(void)mp3;  // unused but kept for structure compatibility

    int x = *size;

    *size = ((x >> 24) & 0xFF) |
            ((x >> 8)  & 0xFF00) |
            ((x << 8)  & 0xFF0000) |
            ((x << 24) & 0xFF000000);
}

