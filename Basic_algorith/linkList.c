#include <stdio.h>

// 結構不能內嵌同一結構，但可內嵌指向同一結構的指標
struct node{
    int data; //資料
    struct node *next; //下一筆記憶體位置
};
typedef struct node Node;

int main(){
    Node a,b,c; //宣告三個節點
    Node *ptr = &a; //宣告ptr，並將他指向節點a

    a.data = 7;
    a.next = &b; // next指標指向節點b

    b.data = 3;
    b.next = &c; // next指標指向節點c

    c.data = 14;
    c.next = NULL; // next指標指向NULL

    while(ptr != NULL){
        printf("address = %p, ", ptr); //印出節點的位址
        printf("data = %d ", ptr->data); //印出節點的資料 
        printf("next = %p\n", ptr->next); //印出下一個節點位址
        ptr = ptr->next;  //將ptr指向下一個節點
    }

    return 0;

    /*
    result:
    address = 000000000061FE00, data = 7 next = 000000000061FDF0
    address = 000000000061FDF0, data = 3 next = 000000000061FDE0
    address = 000000000061FDE0, data = 14 next = 0000000000000000
    */
}