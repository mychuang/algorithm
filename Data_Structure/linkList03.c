/*
建立、列印、釋放空間函數
*/

#include <stdio.h>

struct node{
    int data; //資料
    // 結構不能內嵌同一結構，但可內嵌指向同一結構的指標
    struct node *next; //下一筆記憶體位置
};
typedef struct node Node;

//建立鏈結串列
Node *createList(int *arr, int len){
    Node *first, *current, *previous;
    
    for(int i=0; i<len; i++){
        current = (Node *)malloc(sizeof(Node)); //動態配置記憶體給新節點
        current->data = arr[i];

        if(i==0){
            first = current;
        }else{
            previous->next = current; //把前一個的next指向目前的節點
        }

        current->next = NULL; //把目前的節點的next指向NULL
        previous = current; //把前一個節點設成目前的節點
    }
    return first;
}

//打印鏈結串列
Node printList(Node *first){
    Node *current = first; //設current為第一個節點
    
    if(current == NULL){
        printf("List is empty! \n");
    }else{
        while(current != NULL){
            printf("address = %p, ", current); //印出節點的位址
            printf("data = %d ", current->data); //印出節點的資料 
            printf("next = %p\n", current->next); //印出下一個節點位址
            current = current->next;  //將ptr指向下一個節點
        }
    }
}

//釋放鏈結串列記憶空間
void freeList(Node *first){
    Node *current = first; //設current為第一個節點
    Node *tmp;

    /*進行迴圈，逐個釋放記憶體*/
    while(current != NULL){
        tmp = current; // 將current 暫存給tmp
        current = current->next; //current指向下一個node
        free(tmp); //釋放記憶體
    }
}

int main(){
    Node *first;
    int arr[] = {7, 3, 14};

    //建立鏈結串列
    first = createList(arr, 3);

    //打印鏈結串列
    printList(first);

    //釋放鏈結串列記憶空間
    freeList(first);
    return 0;

    /*
    result:
    address = 0000000000B77BE0, data = 7 next = 0000000000B77C00
    address = 0000000000B77C00, data = 3 next = 0000000000B77C20
    address = 0000000000B77C20, data = 14 next = 0000000000000000
    */
}