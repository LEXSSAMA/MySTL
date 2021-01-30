#pragma once 

class Fib{
    private:
     int first , second;
    public:
    Fib (int n){
        first = 1; second = 0; /*Suppose f(-1) == 1 , f(0) == 0*/
        while(second<n) {next();}
    }
    int get() {return second;}
    int prev() {first = second-first; second -= first;}
    int next() {second += first; first = second - first;}
};