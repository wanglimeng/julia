#ifndef _JULIA_STRING_H_
#define _JULIA_STRING_H_

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char* data;
    int len;
} string_t;


#define STRING(cstr)    (string_t){cstr, sizeof(cstr) - 1}


static const string_t string_null = {NULL, 0};

static inline void string_init(string_t* str)
{
    str->data = NULL;
    str->len = 0;
}

static inline char* string_find(string_t* str, char ch)
{
    for (int i = 0; i < str->len; i++)
        if (str->data[i] == ch)
            return &str->data[i];
    return NULL;
}

static inline string_t string_setto(char* cstr, int len)
{
    return (string_t){cstr, len};
}

static inline char* string_end(string_t* str)
{
    return str->data + str->len;
}

int print_string(const char* format, ...);
int string_cmp(string_t* lhs, string_t* rhs);
bool string_eq(string_t* lhs, string_t* rhs);

#endif
