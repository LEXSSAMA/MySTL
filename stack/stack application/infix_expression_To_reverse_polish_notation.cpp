//将中缀表达式转化为逆波兰表达式(reverse_polish_notation)

#include <stdio.h>
#include "stack/stack.h"

#define N_OPTR 9
const char op_table[N_OPTR][N_OPTR]{
            /*  '+'    '-'   '*'   '/'   '!'   '^'  '('   ')'  '\0'*/
   /*'+'*/      {'>' , '>' , '<' , '<' , '<' , '<' , '<' , '>' , '>'},
   /*'-'*/      {'>' , '>' , '<' , '<' , '<' , '<' , '<' , '>' , '>'},
   /*'*'*/      {'>' , '>' , '>' , '>' , '<' , '<' , '<' , '>' , '>'},
   /*'/'*/      {'>' , '>' , '>' , '>' , '<' , '<' , '<' , '>' , '>'},
   /*'!'*/      {'>' , '>' , '>' , '>' , '>' , '>' , ' ' , '>' , '>'},
   /*'^'*/      {'>' , '>' , '>' , '>' , '<' , '<' , '<' , '>' , '>'},
   /*'('*/      {'<' , '<' , '<' , '<' , '<' , '<' , '<' , '=' , ' '},
   /*')'*/      {' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '},
   /*'\0'*/     {'<' , '<' , '<' , '<' , '<' , '<' , '<' , ' ' , '='}
};

bool isDigit(char const& e){ return (e=='.'||(e>='0'&&e<='9'))?true:false; }

int getindex(char const& op){
    switch (op)
    {
        case '+':   return 0;
        case '-':   return 1;
        case '*':   return 2;
        case '/':   return 3;
        case '!':   return 4;
        case '^':   return 5;
        case '(':   return 6;
        case ')':   return 7;
        case '\0':  return 8;
    }
    return -1;
}
char orderBetween(char const& op_top,char const & op_expr){
    int top = getindex(op_top); int expr = getindex(op_expr);
    return op_table[top][expr];
}
void changeToRPN(char*  expr,char* RPN){
    stack<char> optr; optr.push('\0');
    optr.push('\0');
    while(!optr.empty()){
        if(isDigit(*expr)) *RPN++=*expr++;
        else{
            switch (orderBetween(optr.top(),*expr)){
                case '>': *RPN++ = optr.pop(); break;
                case '<': optr.push(*expr++) ; break;
                case '=': optr.pop();expr++; break;
            }
        }
    }
}

int main(){
    printf("Please input infix expression :\n");
    char expr[100]; char RPN[100];
    scanf("%s",expr);
    changeToRPN(expr,RPN);
    printf("%s\n",RPN);
    return 0;
}