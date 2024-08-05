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

Vstr vstr_s(const char *s);
Vstr vstr_n(const char *s, size_t n);
bool vstr_cmp(const Vstr v1, const Vstr v2);
const char *vstr_str(const Vstr haystack, const Vstr needle);
Vstr vstr_chop(Vstr v, const char *delims);
Vstr vstr_substr(Vstr v, size_t start, size_t stop);
Vstr vstr_trim(Vstr v);
Vstr vstr_trim_left(Vstr v);
Vstr vstr_trim_right(Vstr v);

#endif
