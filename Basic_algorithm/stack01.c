/*
使用陣列製作堆疊
*/

#include <stdio.h>
#include <stdbool.h> /*C99 在標頭檔 <stdbool.h> 中定義布林*/
/*Chck bool in c: https://reurl.cc/KbA4gj */

#define MAXSTACK 5  /*定義最大堆疊容量*/
int stack[MAXSTACK];  //堆疊的陣列宣告
int top = -1;		//The index of the stack top

bool isEmpty(); //判斷是否為空堆疊, 是則傳回True
void push(int); //將指定的資料存入堆疊
int pop(); //從堆疊取出資料

int main(){
    int var;
    printf("Enter 5 values: \n");
    for(int i=0; i<5; i++){
        scanf("%d", &var);
        push(var);
    }
    printf("-------------------------\n");

    while(!isEmpty()){
        printf("Pop the values = %d\n", pop());
    }

    return 0;

    /*
    result:
    Enter 5 values: 
    1
    2
    3
    4
    5
    -------------------------
    Pop the values = 5
    Pop the values = 4
    Pop the values = 3
    Pop the values = 2
    Pop the values = 1
    */
}

//判斷是否為空堆疊, 是則傳回True
bool isEmpty(){
	if(top == -1){
		return true; 
	}else{
		return false;
	}
}

//將指定的資料存入堆疊
void push(int data){
    if(top >= MAXSTACK){
        printf("the stask is full \n");
    }else{
        top++;
        stack[top] = data;
    }
}

//從堆疊取出資料
int pop(){
    if(isEmpty()){
        printf("the stack is empty \n");
    }else{
        int data = stack[top];
        top--;
        return data;
    }
}