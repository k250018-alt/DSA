#include"iostream"
#include"Cir_Singly_ll.h"
using namespace std;
string removePlayers(Circ_sll<string> list){
    int i =0;
    while(list.get_count() > 1){
        i = (i+ 2)%list.get_count();
        list.delete_node(i);
    }
    return list.serach(0);
}
int main(){
    Circ_sll<string> list;
    list.input();
    list.display();
    cout<< "Last standing player "<< removePlayers(list)<<endl;
}