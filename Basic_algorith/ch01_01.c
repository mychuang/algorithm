/*
費伯那序列：
fn = 0, n=0
fn = 1, n=1
fn = fn-1 + fn-2, n=2, 3, 4 ...
*/

#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    if(n<0){
        printf("n need to larger than 0");
    }     

    if(n == 0){
       return 0;
    }else if(n == 1 || n == 2){
       return 1;
    }else{
       return fib(n-1) + fib(n-2);
    }

}

int main(){
    int n;
    printf("enter the 費伯那序列 fn = ");
    scanf("%d", &n);

    for(int i=0; i<=n; i++){
        printf("fib(%d) = %d\n", i, fib(i));
    }

    return 0;
}
