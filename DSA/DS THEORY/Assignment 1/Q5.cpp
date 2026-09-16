#include"iostream"
#include"Singly_ll.h"
using namespace std;

struct Product{
    int Id;
    string productName;
    string Category;
    float price;
};
ostream& operator<<(ostream&os ,const Product&r){
       os <<  r.Id <<" : " << r.productName << " : " << r.Category <<" : "<< r.price ;
       return os;
    }
istream& operator>>(istream&is ,Product &r){
    is >>r.Id >> r.productName >> r.Category >> r.price;
    return is;
}
Singly_LL<Product> inputcheck(Singly_LL<Product> &list){
    Product prod;
    cout << "Enter the product info: "<<endl;
    cin >> prod;
    if(list.get_count() == 0){
        list.insert(prod);
        return list;
    }
    for(int i = 0 ; i < list.get_count() ; i++) {
        if(prod.Id == list.search_Node(i).Id){
            if(prod.price < list.search_Node(i).price){
                list.insertinbetween(prod,i);
                list.delete_node(i);
                return list;
            }
            return list;
        }
        else if(prod.Id < list.search_Node(i).Id){
            if(i ==  0){
                list.inserthead(prod);
                return list;
            }
            list.insertinbetween(prod,i-1);
            return list;
        } 
    }
    list.insert(prod);
    return list;
}
Singly_LL<Product> mergelist(Singly_LL<Product> list1 ,Singly_LL<Product> list2){
    bool added = true;
    for(int i =0 ; i < list1.get_count() ; i++){
        added =false;
        for(int j =0 ; j <list2.get_count() ; j++){
            if(list1.search_Node(i).Id == list2.search_Node(j).Id){
                added = true;
                if(list1.search_Node(i).price < list2.search_Node(j).price){
                    list2.insertinbetween(list1.search_Node(i),j);
                    list2.delete_node(j);
                    break;
                }
                break;
            }
            else if(list1.search_Node(i).Id < list2.search_Node(j).Id){
                added =true;
                if(j == 0 ){
                    list2.inserthead(list1.search_Node(i));
                    break;
                }
                list2.insertinbetween(list1.search_Node(i),j-1);
                break;
            }
        }
        if(!added){
            list2.insert(list1.search_Node(i));
        }
    }
    return list2;
}
int main(){
    Singly_LL<Product> Glowcare;
    Singly_LL<Product> BeautyHub;
    char choice;
    cout << "Enter the product for glowcare"<< endl;
    do {
        Glowcare = inputcheck(Glowcare);
        cout <<"enter x to exit the input"<<endl;
        cin >> choice;
    }while(choice != 'x');
    cout << "Enter the product for BeautyHub"<<endl;
    do {
        BeautyHub = inputcheck(BeautyHub);
        cout <<"enter x to exit the input"<<endl;
        cin >> choice;
    }while(choice != 'x');
    Glowcare.display();
    BeautyHub.display();
    Singly_LL<Product> merged;
    merged = mergelist(Glowcare,BeautyHub);
    merged.display();
    float totalval =0;
    for(int i = 0 ; i < merged.get_count() ; i++){
        totalval += merged.search_Node(i).price;
    }
    cout << "Total value of the products "<< totalval <<endl;
}