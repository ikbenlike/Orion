#ifndef __STRING_H_
    #define __STRING_H_
    #include <stddef.h>

    #ifdef __cplusplus
        extern "C" {
    #endif

    size_t strlen(const char *str);
    void *memset(void *bufptr, int value, size_t size);
    void *memmove(void* dstptr, const void* srcptr, size_t size);
    void *memcpy(void *restrict dstptr, const void *restrict srcptr, size_t size);
    int memcmp(const void *aptr, const void *bptr, size_t size);
    void *memchr(const void *str, int c, size_t n);
    char *strcpy(char *dest, const char *src);
    char *strncpy(char *dest, const char *src, size_t n);

    #ifdef __cplusplus
        }
    #endif
#endif
