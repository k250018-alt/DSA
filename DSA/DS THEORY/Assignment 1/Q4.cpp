#include"iostream"
#include"Circullar_LL.h"
using namespace std;
struct Rider{
    int id;
    string name;
    int no_of_assigned;
};
ostream& operator<<(ostream&os ,const Rider&r){
       os <<  r.id <<" : " << r.name << " : " << r.no_of_assigned ;
       return os;
    }
istream& operator>>(istream&is ,Rider &r){
    is >>r.id >> r.name >> r.no_of_assigned;
    return is;
}

int main(){
    Circ_sll<Rider> rider_list;
    rider_list.input(); //enter at least 7 riders 
    rider_list.display();
    rider_list.delete_head();
    rider_list.display();
    rider_list.delete_tail();
    rider_list.display();
    Rider addrider = rider_list.serach(4);
    rider_list.insert(addrider);
    rider_list.display();
    rider_list.inserthead(addrider);
    rider_list.display();
    rider_list.inserinbetween(addrider,4);
    rider_list.display();    
}