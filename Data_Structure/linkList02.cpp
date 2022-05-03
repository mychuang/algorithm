#include <iostream>

class Node{
public:
    int data;
    Node *next;
    
    explicit Node(){
        data = 0;
        next = nullptr;
    };

};

int main(){
    int num;
    printf("Number of nodes: ");
    scanf("%d", &num);

    Node *head, *current, *tail;
    for(int i=0; i<num; i++){
        current = new Node(); //動態配置記憶體給新節點
        printf("Data for node %d: ",i+1);
        scanf("%d", &current->data); //輸入節點的data成員
        printf("New Node = %p, \n", current); //印出節點的位址
        
        if(i==0){
            head = current;
        }else{
            tail->next = current;
        }
        current->next = nullptr;
        tail = current; //把前一個節點設成目前的節點

        printf("First Node = %p, \n", head); //印出節點的位址
        printf("previous Node = %p, \n", tail); //印出節點的位址
    }

    //current = first; //設current為第一個節點
    //while(current != NULL){
    //    printf("address = %p, ", current); //印出節點的位址
    //    printf("data = %d ", current->data); //印出節點的資料 
    //    printf("next = %p\n", current->next); //印出下一個節點位址
    //    current = current->next;  //將ptr指向下一個節點
    //}

    return 0;
}
