#include <json.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


JSONobj* json_parse_string(char* string)
{
    JSONobj* output = malloc( (size_t)sizeof( JSONobj ) ); // needs to be freed if not used

    char * bruh = strtok(string, "\"");
    while (bruh != NULL)
    {   
        printf("%s\n", bruh);
        bruh = strtok(NULL, "\n\",");
    }
    return output;
}