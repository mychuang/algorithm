#include <iostream>

/*Define the Node Structure*/
class Node{
public:
    int data;
    Node *next;
    explicit Node(){
        data = 0;
        next = nullptr;
    };
};

class ListNode{
private:
    Node *head = new Node();
    int numNode = 0;
public:
    void pushBack(int data);
    void printList();
    void freeList();
};

void ListNode::pushBack(int data){
    Node *current, *tail;

    current = new Node(); //動態配置記憶體給新節點
    current->data = data;

    if(numNode == 0){
        head = current;
    }else{
        tail->next = current;
    }
    current->next = nullptr;
    tail = current; //把前一個節點設成目前的節點

    numNode++;
}

void ListNode::printList(){
    Node *current = head;
    while(current != NULL){
        printf("address = %p, ", current); //印出節點的位址
        printf("data = %d ", current->data); //印出節點的資料 
        printf("next = %p\n", current->next); //印出下一個節點位址
        current = current->next;  //將ptr指向下一個節點
    }
}

void ListNode::freeList(){
    Node *current = head;
    Node *tmp;

    while(current != NULL){
        printf("Release address = %p \n", current); //印出節點的位址
        tmp = current;
        current = current->next;
        free(tmp);
    }
}

int main(){
    int num;
    ListNode listNode;

    listNode.pushBack(7);
    listNode.pushBack(3);
    listNode.pushBack(14);

    listNode.printList();

    listNode.freeList();
    return 0;

    /*
    result:
    address = 010220B8, data = 7 next = 010220C8
    address = 010220C8, data = 3 next = 010220D8
    address = 010220D8, data = 14 next = 00000000
    Release address = 00FE20B8
    Release address = 00FE20C8
    Release address = 00FE20D8
    */
}
