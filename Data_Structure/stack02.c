/*
使用鏈結串列(Link list)製作堆疊
*/

#include <stdio.h>
#include <stdbool.h> /*C99 在標頭檔 <stdbool.h> 中定義布林*/
/*Chck bool in c: https://reurl.cc/KbA4gj */

struct node{
    int data; //資料
    struct node *next; //下一筆記憶體位置
};
typedef struct node Node;

Node* top = NULL; //指向堆疊頂端的指標

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
    pop();

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
    the stack is empty
    */
}

//判斷是否為空堆疊, 是則傳回True
bool isEmpty(){
	if(top == NULL){
		return true; 
	}else{
		return false;
	}
}

//將指定的資料存入堆疊
void push(int data){
    Node *newNode; //新節點的指標
    /*配置新節點的記憶體*/
    newNode = (Node *)malloc(sizeof(Node)); //動態配置記憶體給新節點
    newNode->data = data;  //輸入節點的data成員 
	newNode->next = top;   //將新節點指向堆疊的點端 
	top = newNode;         //新節點成為堆疊的頂端
}

//從堆疊取出資料
int pop(){
    Node* ptr;

    if(isEmpty()){
        printf("the stack is empty \n");
    }else{
        ptr = top; //指向堆疊的頂端，因為永遠從頂端刪除資料
        int temp = ptr->data; //取出堆疊資料
        top = ptr->next; //將堆疊頂端的指標指向下一個節點
        free(ptr);
        return temp;
    }
}