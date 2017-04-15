#include <ctypes.h>

int isalnum(int c){
    if(isalpha(c)){
        return 1;
    }
    else if(isdigit(c)){
        return 1;
    }
    return 0;
}
