#include <stdio.h>
int main() {
    unsigned char a = 5; //Bit: 0000 0101
    unsigned char b = 9; //Bit: 0000 1001
  
    printf("a = %d, b = %d\n", a, b);

    printf("a&b = %d\n", a & b);  //0000 0001
  
    printf("a|b = %d\n", a | b); //0000 1101
  
    printf("~a = %d\n", a = ~a); //1111 1010
  
    printf("b<<1 = %d\n", b << 1); //0001 0010
  
    printf("b>>1 = %d\n", b >> 1); // 0000 0100
  
    return 0;
}