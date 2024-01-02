#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <json.h>

char string[1024];

int main()
{
    FILE* json_file = fopen("json_example.json", "r");
    if (json_file == NULL)
    {
        perror("null file read");
        return 1;
    }

    /* Get the number of bytes */
    fseek(json_file, 0L, SEEK_END);
    long numbytes = ftell(json_file);
    
    /* reset the file position indicator to the beginning of the file */
    fseek(json_file, 0L, SEEK_SET);	

    if (numbytes > 1024)
    {
        perror("too long file");
        return 1;
    }

    fread(string, sizeof(*string), numbytes, json_file);

    JSONobj *freeme = json_parse_string(string);

    free(freeme);

    fclose(json_file);

    return 0;
}