#include "iostream"
using namespace std;
#include "Singly_ll.h"
Singly_LL<int> arrange(Singly_LL<int> &list){
    Singly_LL<int> newlist;
    for(int i = 0; i< list.get_count() ; i++){
        if(list.search_Node(i) % 2 == 0){
            newlist.insert(list.search_Node(i));
        }
    }
    for(int i= 0 ; i < list.get_count() ; i++){
        if(list.search_Node(i) %2 != 0){
            newlist.insert(list.search_Node(i));
        }
    }
    while(list.get_count() != 0)list.delete_node(0);
    return newlist;
}
int main(){
    Singly_LL<int> list;
    list.input();
    list.display();
    list = arrange(list);
    cout<<"Arranged list :"<<endl;
    list.display();
}