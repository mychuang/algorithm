/* 使用鏈結串列(Link list)製作堆疊 */
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

class Stack{
private:
    Node *top = new Node();
    int numNode = 0;
public:
    bool isEmpty(); //判斷是否為空堆疊, 是則傳回True
    void push(int); //將指定的資料存入堆疊
    int pop(); //從堆疊取出資料
};

//判斷是否為空堆疊, 是則傳回True
bool Stack::isEmpty(){
	if(numNode == 0){
		return true; 
	}else{
		return false;
	}
}

//將指定的資料存入堆疊
void Stack::push(int data){
    Node *newNode = new Node();
    newNode->data = data;  //輸入節點的data成員
	newNode->next = top;   //將新節點指向堆疊的點端 
	top = newNode;         //新節點成為堆疊的頂端
    numNode++;
}

//從堆疊取出資料
int Stack::pop(){
    Node* ptr;

    if(isEmpty()){
        printf("the stack is empty \n");
    }else{
        ptr = top; //指向堆疊的頂端，因為永遠從頂端刪除資料
        int temp = ptr->data; //取出堆疊資料
        top = ptr->next; //將堆疊頂端的指標指向下一個節點
        free(ptr);
        numNode--;
        return temp;
    }
}

int main(){
    Stack stack;

    int var;
    printf("Enter 5 values: \n");
    for(int i=0; i<5; i++){
        scanf("%d", &var);
        stack.push(var);
    }
    printf("-------------------------\n");

    while(!stack.isEmpty()){
        printf("Pop the values = %d\n", stack.pop());
    }
    stack.pop();
    return 0;
}