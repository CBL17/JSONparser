#include <json.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void json_parse_string(char* string, uint32_t len)
{
    char *start;
    char *end;

    for (uint32_t i = 0; i < len; i++)
    {
        if (isspace(string[i]))
        {
            continue;
        }
        else if (string[i] == '\"')
        {
            end = strtok(string+i, "\"");
            if (end == NULL)
            {
                printf("Unexpected end of string!");
                return;
            }
            else
            {
                printf("%s\n", end);
                i += (int)(end-(string+i));
                continue;
            }
        }
        else if (string[i] == ':')
        {
            printf(":\n");
            continue;
        }
        else if (isdigit(string[i]))
        {
            printf("%lld\n", strtoll(string+i, &end, 0));
            i += (int)(end-(string+i));
            continue;
        }
        else if (string[i] == '{')
        {
            continue;
        }
        else if (isalpha(string[i]))
        {
            continue;
        }
    }
    return;
}


JSONobj* init_json_obj(const char *name, void* data, TYPE type)
{
    JSONobj* output = malloc( (size_t)sizeof( JSONobj ) );

    output->name    = name;
    output->child   = NULL;
    output->next    = NULL;
    output->prev    = NULL;

    switch (type)
    {
    case CHAR:
        output->value.integer = *(char*)data;
        break;
    case INT:
        output->value.integer = *(int*)data;
        break;
    case FLOAT:
        output->value.fpoint = *(double*)data;
        break;
    case STRING:
        output->value.string = (char*)data;
        break;
    default:
        break;
    }

    return output;
}