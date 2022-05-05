/*使用鏈結串列(Link list)製作Queue*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> /*C99 在標頭檔 <stdbool.h> 中定義布林*/

struct node{
    int data; //資料
    struct node *next; //下一筆記憶體位置
};
typedef struct node Node;

Node* front = NULL; //指向queue front 的指標
Node* rear = NULL; //指向queue rear 的指標

void push(int); //將指定的資料存入queue
int pop(); //從queue 取出資料

int main(){
    int var;
    printf("Enter 5 values: \n");
    for(int i=0; i<5; i++){
        scanf("%d", &var);
        push(var);
    }
    printf("-------------------------\n");
    
    for(int i=0; i<5; i++){
        printf("Pop the values = %d\n", pop());
    }
    pop();

    return 0;
}

//將指定的資料存入queue
void push(int data){
    Node *newNode; //新節點的指標

    /*配置新節點的記憶體*/
    newNode = (Node *)malloc(sizeof(Node));
    printf("New Node = %p, \n", newNode); //印出節點的位址
    newNode->data = data;

    if(rear == NULL){
        front = newNode;
    }else{
        rear->next = newNode; //將新節點指向queue的尾端
    }
    newNode->next = NULL;
    rear = newNode;
}

//
int pop(){
    Node *ptr;

    if(front == NULL){
        printf("the queue is empty \n");
        return 0;
    }else{
        ptr = front; //指向queue front，因為永遠從front刪除資料
        printf("delete Node = %p, \n", ptr); //印出節點的位址

        front = ptr->next; //將queue front 指向下一個節點 
        int temp = ptr->data; //取出queue資料
        free(ptr);
        return temp;
    }
}