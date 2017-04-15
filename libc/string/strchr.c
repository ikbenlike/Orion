#include <stddef.h>
#include <string.h>

char *strchr(const char *str, int c){
    const unsigned char *cstr = (const unsigned char*)str;
    const unsigned char cc = (const unsigned)c;
    while(cstr != NULL){
        if(cstr == cc){
            return cstr;
        }
    }
    return NULL;
}
