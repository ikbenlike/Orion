#include <ctypes.h>

int iscntrl(int c){
    switch(c){
        case '\a':
            return 1;
            break;
        case '\b':
            return 1;
            break;
        case '\f':
            return 1;
            break;
        case '\n':
            return 1;
            break;
        case '\r':
            return 1;
            break;
        case '\t':
            return 1;
            break;
        case '\v':
            return 1;
            break;
        case '\\':
            return 1;
            break;
        case '\'':
            return 1;
            break;
        case '\"':
            return 1;
            break;
        case '\?':
            return 1;
            break;
        case '\e':
            return 1;
            break;
        default:
            return 0;
            break;
    }
    return 0;
}
