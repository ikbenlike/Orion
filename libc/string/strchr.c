#include <stddef.h>
#include <string.h>

char *strchr(const char *str, int c){
    char *cstr = (char*)str;
    const unsigned char cc = (const unsigned char)c;
    for(size_t i = 0; cstr[i] != '\0'; i++){
        if(str[i] == cc){
            return &cstr[i];
        }
    }
    return NULL;
}
