#include <ctypes.h>

int ispunct(int c){
    switch(c){
        case '!':
            return 1;
            break;
        case '"':
            return 1;
            break;
        case '#':
            return 1;
            break;
        case '$':
            return 1;
            break;
        case '%':
            return 1;
            break;
        case '&':
            return 1;
            break;
        case '\'':
            return 1;
            break;
        case '(':
            return 1;
            break;
        case ')':
            return 1;
            break;
        case '*':
            return 1;
            break;
        case '+':
            return 1;
            break;
        case ',':
            return 1;
            break;
        case '.':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '/':
            return 1;
            break;
        case ':':
            return 1;
            break;
        case ';':
            return 1;
            break;
        case '<':
            return 1;
            break;
        case '>':
            return 1;
            break;
        case '=':
            return 1;
            break;
        case '?':
            return 1;
            break;
        case '@':
            return 1;
            break;
        case '[':
            return 1;
            break;
        case ']':
            return 1;
            break;
        case '\\':
            return 1;
            break;
        case '^':
            return 1;
            break;
        case '_':
            return 1;
            break;
        case '`':
            return 1;
            break;
        case '{':
            return 1;
            break;
        case '}':
            return 1;
            break;
        case '|':
            return 1;
            break;
        case '~':
            return 1;
            break;
        default:
            return 0;
            break;
    }
    return 0;
}
