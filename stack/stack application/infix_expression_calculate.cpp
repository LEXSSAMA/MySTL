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

bool isDigit(char & S){return (S<='9'&&S>='0')?true:false;}

void readNum(stack<float>& opnd,char* & S){
    float res = 0.0; bool po = false;
    while((*S=='.')||(*S<='9'&&*S>='0')){
        if(*S=='.') po = true;
        else if(*S<='9'&&*S>='0'&&po)
            res += (*S-'0')*1.0/10;
        else
            res = res*10+(*S-'0');
        S++;
    }
    opnd.push(res);
}
int op_table_index(char const& op){
    switch (op)
    {
    case '+':  return 0;
    case '-':  return 1;
    case '*':  return 2;
    case '/':  return 3;
    case '!':  return 4;
    case '^':  return 5;
    case '(':  return 6;
    case ')':  return 7;
    case '\0': return 8;
    }
    return -1;
}

char orderBetween(char const& op_top,char const& S){
    int top_index = op_table_index(op_top); int s_index = op_table_index(S);
    return op_table[top_index][s_index];
}

void calcu(char const& op,stack<float>& opnd){
    if(op=='!') {
        float opnd1 = opnd.pop();
        if(opnd1==0) opnd.push(1.0);
        else{
            int i = opnd1;
            while(--i) opnd1*=i;
            opnd.push(opnd1);
        }
    }else{
        float opnd2 = opnd.pop(); float opnd1 = opnd.pop();
        switch (op)
        {
            case '+':  opnd1 = opnd1+opnd2; break;
            case '-':  opnd1 = opnd1-opnd2; break;
            case '*':  opnd1 = opnd1*opnd2; break;
            case '/':  opnd1 = opnd1/opnd2; break;
            case '^':  {                    
                float base = opnd1;
                while(1<opnd2--) opnd1*= base;
                break;
            } 
        }
        opnd.push(opnd1);
    }
}

float evaluate(char* S){
    stack<float> opnd; stack<char> optr;
    optr.push('\0');
    while(!optr.empty()) {
        if(isDigit(*S))
            readNum(opnd,S);
        else{
            switch (orderBetween(optr.top(),*S))
            {
            case '>':{
                char op = optr.pop();
                calcu(op,opnd);
                break;
            }
            case '=':
                optr.pop(); S++;
                break;
            case '<':
                optr.push(*S); S++;
                break;
            }
        }
    }
    return opnd.pop();
}

int main(){
    char S[1000];
    printf("Please input expressions that you want to calculate!\n");
    scanf("%s",S);
    printf("%s = %lf\n",S,evaluate(S));
    return 0;
}