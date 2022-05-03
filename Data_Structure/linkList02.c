/*
以動態malloc()的方式來配置記憶空間給每一個節點
*/

#include <stdio.h>

struct node{
    int data; //資料
    // 結構不能內嵌同一結構，但可內嵌指向同一結構的指標
    struct node *next; //下一筆記憶體位置
};
typedef struct node Node;

int main(){
    int num;
    printf("Number of nodes: ");
    scanf("%d", &num);
    
    Node *head, *current, *tail;
    for(int i=0; i<num; i++){
        current = (Node *)malloc(sizeof(Node)); //動態配置記憶體給新節點

        printf("Data for node %d: ",i+1);
        scanf("%d", &(current->data)); //輸入節點的data成員

        if(i==0){
            head = current;
        }else{
            tail->next = current; //把前一個的next指向目前的節點
        }
        current->next = NULL; //把目前的節點的next指向NULL
        tail = current; //把前一個節點設成目前的節點
    }

    current = head; //設current為第一個節點
    while(current != NULL){
        printf("address = %p, ", current); //印出節點的位址
        printf("data = %d ", current->data); //印出節點的資料 
        printf("next = %p\n", current->next); //印出下一個節點位址
        current = current->next;  //將ptr指向下一個節點
    }

    return 0;

    /*
    result:
    Number of nodes: 3
    Data for node 1: 10
    Data for node 2: 15
    Data for node 3: 20
    address = 00000000007D7BE0, data = 10 next = 00000000007D7C00
    address = 00000000007D7C00, data = 15 next = 00000000007D7C20
    address = 00000000007D7C20, data = 20 next = 0000000000000000
    */
}