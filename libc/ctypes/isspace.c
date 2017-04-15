#include <ctypes.h>

int isspace(int c){
    switch(c){
        case '\v':
            return 1;
            break;
        case '\t':
            return 1;
            break;
        case '\f':
            return 1;
            break;
        case '\r':
            return 1;
            break;
        case ' ':
            return 1;
            break;
        default:
            return 0;
            break;
    }
    return 0;
}
