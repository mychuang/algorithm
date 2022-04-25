/*
Define n! = n * (n-1) * (n-2) 
*/

#include <stdio.h>
#include <stdlib.h>

int fac(int n){
    int sum = 0;

    if( n==0 ){
       return 1;
    }else{
       sum = n * fac(n-1);
    }
    return sum;
}

int main(){
    int n;
    printf("enter factorical(n), n= ");
    scanf("%d", &n);

    for(int i =0; i<=n; i++){
        printf("%d \n", fac(i));
    }

    return 0;
}
