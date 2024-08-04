#ifndef VSTR_INCLUDED
#define VSTR_INCLUDED

#include <stddef.h>
#include <stdbool.h>
#include <string.h>

struct Vstr {
  char *buf;  // String data
  size_t len; // String len
};
typedef struct Vstr Vstr;

#define Vstr_Fmt "%.*s"
#define Vstr_Arg(vstr) (int) (vstr).len, (vstr).buf
#define VSTR(cstr) vstr_n(cstr, sizeof(cstr) - 1)
#define VSTR_NULL vstr_n(NULL, 0)

