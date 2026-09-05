#include "iostream"
using namespace std;
#include "Singly_ll.h"
void palindrome(Singly_LL<char>& list){
    for(int i = 0 ; i < list.get_count() ;i++){
        if(list.search_Node(i) != list.search_Node(list.get_count()-i-1)){
            cout <<"not a plaindrome"<<endl;;
        }
    }
    cout<<"pallindrome"<<endl;
}
int main(){
    Singly_LL<char> list;
    list.input();
    list.display();
    palindrome(list);
}
