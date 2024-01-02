#pragma once

typedef struct JSONobj
{
    struct JSONobj *next;
    struct JSONobj *prev;
    struct JSONobj *child;

    char *name;
    void *data;

} JSONobj;

JSONobj* json_parse_string(char* string);
