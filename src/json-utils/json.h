#include <stdint.h>

#pragma once

typedef enum {
    CHAR,
    INT,
    FLOAT,
    STRING
} TYPE;

typedef struct JSONobj
{
    struct JSONobj *next;
    struct JSONobj *prev;
    struct JSONobj *child;

    char *name;
    union data
    {
        char* string;
        uint32_t integer;
        double fpoint;
    } value;
    

} JSONobj;


void json_parse_string(char* string, uint32_t len);
JSONobj* init_json_obj(const char *name, void* data, TYPE type);
