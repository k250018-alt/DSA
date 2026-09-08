#include "iostream"
using namespace std;
#include "Singly_ll.h"
Singly_LL<int> arrange(Singly_LL<int> &list){
    for(int i = 0 ; i < list.get_count() ; i++){
        for (int  j = i ; j < list.get_count()-1 ; j++){
            if(list.search_Node(j) % 2 != 0 && list.search_Node(j+1)%2 ==0){
                list.insertinbetween(list.search_Node(j) , j);
                list.insertinbetween(list.search_Node(j+2),j);
                list.delete_node(j+3);
                list.delete_node(j);
            }
        }
    }
    return list;
}
int main(){
    Singly_LL<int> list;
    list.input();
    list.display();
    list = arrange(list);
    cout<<"Arranged list :"<<endl;
    list.display();
}
