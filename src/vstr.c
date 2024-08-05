#include "../include/vstr.h"

Vstr vstr_s(const char *s){
    Vstr v = {(char *)s, s == NULL ? 0 : strlen(s)};
    return v;
}
Vstr vstr_n(const char *s, size_t n){
    Vstr v = {(char *)s, n};
    return v;
}
bool vstr_cmp(const Vstr v1, const Vstr v2){
    size_t i = 0;
    while (i < v1.len && i < v2.len) {
        int c1 = v1.buf[i];
        int c2 = v2.buf[i];
        if (c1 < c2) return false;
        if (c1 > c2) return true;
        i++;
    }
    if (i < v1.len) return true;
    if (i < v2.len) return false;
    return false;
}
const char *vstr_str(const Vstr haystack, const Vstr needle){
    size_t i;
    if (needle.len > haystack.len) return NULL;
    if (needle.len == 0) return haystack.buf;
    for (i = 0; i <= haystack.len - needle.len; i++) {
        if (memcmp(haystack.buf + i, needle.buf, needle.len) == 0) {
            return haystack.buf + i;
        }
    }
    return NULL;
}
Vstr vstr_chop(Vstr v, const char *delims){
    if (v.buf == NULL || v.buf == NULL || v.len == 0 || delims == NULL) {
        // Handle NULL pointer or empty string view
        return vstr_n(NULL, 0);
    }

    size_t i = 0;
    while (i < v.len) {
        int is_delim = 0;
        for (size_t j = 0; delims[j] != '\0'; j++) {
            if (v.buf[i] == delims[j]) {
                is_delim = 1;
                break;
            }
        }
        if (is_delim) {
            break;
        }
        i++;
    }

    Vstr result = vstr_n(v.buf, i);

    if (i < v.len) {
        v.buf  += i + 1;
        v.len -= i + 1;
    } else {
        v.buf  += i;
        v.len -= i;
    }

    return result;
}
Vstr vstr_substr(Vstr v, size_t start, size_t stop){
    if (start >= v.len || stop > v.len || start >= stop) {
        return vstr_n(NULL, 0);
    }
    size_t sub_len = stop - start;
    return vstr_n(v.buf+start,sub_len);
}
static bool is_space(int c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f';
}
Vstr vstr_trim(Vstr v){
    while (v.len > 0 && is_space((int) *v.buf)) v.buf++, v.len--;
    while (v.len > 0 && is_space((int) *(v.buf + v.len - 1))) v.len--;
    return v; 
}
Vstr vstr_trim_left(Vstr v){
    while (v.len > 0 && is_space((int) *v.buf)) v.buf++, v.len--;
    return v;
}
Vstr vstr_trim_right(Vstr v){
    while (v.len > 0 && is_space((int) *(v.buf + v.len - 1))) v.len--;
    return v;
}


