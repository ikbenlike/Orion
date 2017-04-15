#include <ctypes.h>

int isxdigit(int c){
    if(isdigit(c)){
        return 1;
    }
    else{
        switch(c){
            case 'a':
                return 1;
                break;
            case 'A':
                return 1;
                break;
            case 'b':
                return 1;
                break;
            case 'B':
                return 1;
                break;
            case 'c':
                return 1;
                break;
            case 'C':
                return 1;
                break;
            case 'd':
                return 1;
                break;
            case 'D':
                return 1;
                break;
            case 'e':
                return 1;
                break;
            case 'E':
                return 1;
                break;
            case 'f':
                return 1;
                break;
            case 'F':
                return 1;
                break;
            default:
                return 0;
                break;
        }
    }
    return 0;
}
