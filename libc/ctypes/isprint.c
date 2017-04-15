#include <ctypes.h>

int isprint(int c){
    if(isalnum(c)){
        return 1;
    }
    else if(ispunct(c)){
        return 1;
    }
    return 0;
}
