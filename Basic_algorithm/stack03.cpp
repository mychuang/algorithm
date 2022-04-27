/*
依序走訪輸入字串，配對左右括號
利用 stack 儲存每個左括號位置
每當遇到一個右括號就消除 stack 中最後出現的左括號
不匹配的右括號顯示'^'，其餘顯示'-'
參考stack01.c
gcc stack03.cpp -lstdc++
*/
#include <iostream>
#include <string.h>

#define MAXSTACK 5  /*定義最大堆疊容量*/
int stack[MAXSTACK];  //堆疊的陣列宣告
int top = -1;		//The index of the stack top

char in[MAXSTACK], ans[MAXSTACK]; //宣告輸入與輸出陣列
int pos[MAXSTACK];

bool isEmpty(); //判斷是否為空堆疊, 是則傳回True

int main() {

    while( std::cin >> in) {
        
        //check ')' error
        int len;
        if(strlen(in) <= MAXSTACK){
            len = strlen(in); //輸入資料的長度
        }else{
            len = MAXSTACK;
        }
        
        //依序走訪輸入字串
        for(int i=0; i<len; i++) {
            ans[i] = '-';

            //將左括號儲存於堆疊 push
            if( in[i] == '(' ) {
               top++;
               pos[top] = i;
            }
            else if( in[i] == ')' ) {
                /*define pop */
                if(isEmpty()){
                    ans[i] = '^'; 
                }else{
                    top--;
                }
            }
        }

        for(int i=top-1; i>=-1; i-- ){
            ans[pos[i]] = '^';
        }

        ans[len] = NULL;
        std::cout << ans << std::endl;
    }
    return 0;
}

//判斷是否為空堆疊, 是則傳回True
bool isEmpty(){
	if(top == -1){
		return true; 
	}else{
		return false;
	}
}