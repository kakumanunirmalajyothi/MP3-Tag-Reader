/* NAME          : K.NIRMALA JYOTHI
REG NO          : 25048_37
SUBMISSION DATE : 7-5-26

DESCRIPTION:
1. main() Function
    Entry point of the program
    Calls validate_cla() to check command line arguments
    Based on result:
    VIEW → calls view()
    EDIT → calls edit()
    Otherwise → prints error
2. validate_cla()
    Validates user input from command line
    Supports:
    -v filename → View tags
    -e option new_text filename → Edit tags
    --help → Display help
    Stores values into mp3 structure:
    filename
    edit option
    new text
    Returns:
    VIEW, EDIT, or 0 (error)
3. view() Function
    Opens MP3 file in read mode
    Checks if file starts with "ID3" (valid MP3 tag)
    Skips header bytes
    Loops through all tags (frames):
    Reads:
    Tag name (4 bytes)
    Size (4 bytes)
    Flags (2 bytes)
    Converts size using toggle_endianess()
    Prints tag name using tag_to_name()
    Prints data using print_tag_data()
    Stops when:
    Tag is empty
    End of file
4. tag_to_name()
    Converts tag codes into readable names:
    TIT2 → Title
    TPE1 → Artist
    TALB → Album
    TYER → Year
    TCON → Content
    TCOM → Comment
    If unknown → prints tag code
5. print_tag_data()
    Reads actual tag content
    Checks for valid size
    Skips first byte (encoding byte)
    Prints remaining data as string
6. edit() Function
    Used to modify a specific tag
    Maps user option to tag:
    -t → Title
    -a → Artist
    -A → Album
    -y → Year
    -m → Content
    -c → Comment
    Steps:
    Open:
    Original file (read mode)
    Temp file (write mode)
    Copy header (first 10 bytes)
    Loop through each tag:
    If tag matches:
    Take new input from user
    Update size
    Write new data
    Skip old data
    Else:
    Copy tag as it is
    Copy remaining audio data
    Replace original file:
    Delete old file
    Rename temp file
7. toggle_endianess()
    Converts byte order (Big Endian ↔ Little Endian)
    Needed because MP3 stores size differently
    Uses bitwise operations

*/


#include "mp3_header.h"

int main(int argc, char *argv[])
{
    /* structure variable declaration */
    struct MP3 mp3;

    int ret = validate_cla(argc,argv,&mp3);
    if(ret == VIEW)
    {
        view(&mp3);
    }
    else if(ret == EDIT)
    {
        edit(&mp3);
    }
    else
    {
        printf("Invalid operation\n");
    }

    return 0;
    

}
