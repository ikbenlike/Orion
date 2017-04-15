#include <stddef.h>
#include <string.h>

void *memchr(const void *str, int c, size_t n){
    unsigned char *cstr = (unsigned char*)str;
    const unsigned char cc = (const unsigned char)c;
    for(size_t i = 0; i < n; i++){
        if(cstr[i] == cc){
            return cstr + i;
        }
    }
    return NULL;
}
