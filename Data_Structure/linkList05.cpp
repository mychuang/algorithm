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
    Node *searchNode(int); //搜尋節點
    void insertNode(Node *, int); //插入節點
    void deleteNode(Node*); //刪除節點
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
        //printf("Release address = %p \n", current); //印出節點的位址
        tmp = current;
        current = current->next;
        free(tmp);
    }
}

Node *ListNode::searchNode(int item){
    Node *current = head;
    while(current != NULL){
        if(current->data == item){
            return current;
        }else{
            current = current->next;
        }
    }
    return NULL;
}

void ListNode::insertNode(Node *node, int item){
    Node *newnode = new Node(); //動態配置記憶體給新節點
    newnode->data = item;
    newnode->next = node->next;
    node->next = newnode;
}

void ListNode::deleteNode(Node *node){
    if(head == NULL){
		printf("Nothing to delete!\n");
        return;
	}

    Node* ptr = head;
    if(node == head){
        head = head->next; //把first指向下一個節點
    }else{
        //找到要刪除之節點的前一個節點
        while(ptr->next != node){
            ptr = ptr->next;
        }
        ptr->next = node->next; //重新設定ptr的next成員
    }
    free(node);
}

int main(){
    int num;
    ListNode listNode;

    listNode.pushBack(7);
    listNode.pushBack(3);
    listNode.pushBack(14);

    printf("---------------------------------------\n");
    listNode.printList();
    printf("---------------------------------------\n");

    Node *node = listNode.searchNode(3); //找出節點值為3的位址
    printf("Print adress of item=3 \n");
    printf("address = %p \n", node); //印出節點的位址
    listNode.deleteNode(node);
    printf("---------------------------------------\n");
    
    listNode.printList();

    listNode.freeList();
    return 0;

    /*
result:
---------------------------------------
address = 00D320B8, data = 7 next = 00D320C8
address = 00D320C8, data = 3 next = 00D320D8
address = 00D320D8, data = 14 next = 00000000
---------------------------------------
Print adress of item=3
address = 00D320C8
---------------------------------------
address = 00D320B8, data = 7 next = 00D320C8
address = 00D320C8, data = 3 next = 00D320E8
address = 00D320E8, data = 46 next = 00D320D8
address = 00D320D8, data = 14 next = 00000000
    */
}
