#include <stddef.h>
#include <string.h>

void *memchr(const void *str, int c, size_t n){
    const unsigned char *cstr = (const unsigned char*)str;
    const unsigned char cc = (const unsigned)c;
    for(size_t i = 0; i < n; i++){
        if(cstr[i] == cc){
            return str + i;
        }
    }
    return NULL;
}
