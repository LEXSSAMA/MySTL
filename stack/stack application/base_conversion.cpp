#define MYSTL_STACK_LIST
#include "stack/stack.h"
#include <stdio.h>


void base_conversion(stack<char>& S,int64_t num , int64_t base){
    char digit[] {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while(num>0){
        S.push(digit[num%base]);
        num /= base;
    }
}
int main(){
    int64_t num , base;
    printf("Please input num that you need to conver:\n");
    scanf("%lld",&num);
    printf("Please input base that you want to conver:\n");
    scanf("%lld",&base);
    stack<char> S;  base_conversion(S,num,base);
    while(!S.empty()) printf("%c ",S.pop());
    return 0;
}