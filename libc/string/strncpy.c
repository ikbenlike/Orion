#include <string.h>
#include <stddef.h>

char *strncpy(char *dest, const char *src, size_t n){
    //size_t i = 0;
    for(size_t i = 0; i < n && src[i] != '\0'; i++){
        dest[i] = src[i];
        if(src[i+1] == '\0' && i+1 < n){
            src[i+1] = '\0';
        }
    }
    return dest;
}
