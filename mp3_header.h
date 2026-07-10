#ifndef MP3_HEADER_H
#define MP3_HEADER_H

#include <stdio.h>
#include <string.h>

#define VIEW 	1
#define EDIT 	2


struct MP3
{
    char *mp3_filename;
    char *edit_option;
    char *new_text;

    FILE *org_mp3_fptr;
    FILE *dup_mp3_fptr;
};
//extern int g_content_size;

int validate_cla(int argc, char *argv[], struct MP3 *mp3);
void view(struct MP3 *mp3);
void edit(struct MP3 *mp3);
void toggle_endianess(struct MP3 *mp3, int *size);
void print_tag_data(struct MP3 *mp3, int content_size);
void tag_to_name(char *);

#endif
