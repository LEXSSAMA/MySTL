#include "stack/stack.h"
#include <string.h>
bool parentheses_match(char* argv){
    stack<char> S; int i = 0;
    int size = strlen(argv);
    while(i<size){
        if(argv[i]=='(') S.push(argv[i]);
        else if(argv[i]==')'&&!S.empty()) S.pop();
        else return false;
        i++;
    }
    return true;
}

int main(int argc, char* argv[]){
    for(int i=1;i<argc;++i){
    if(parentheses_match(argv[i])) printf("Valid expression!\n");
    else printf("Invalid expression!\n");
    }
    return 0;
}

/*实际是只考虑一种括号，用一个计数器就可以模拟栈的行为，例如，遇到'(',计数器就加一，遇到')',计数器就减一，如果计数器变为负数就return false*/

/*用栈的优势就是可以将一种括号推广至多种括号并存的情况，括号是一个广泛的概念:例如 <a></a>,<body></body>也可以当成一个括号*/