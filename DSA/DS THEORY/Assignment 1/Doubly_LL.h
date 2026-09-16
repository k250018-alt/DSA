#include"iostream"
using namespace std;
template <typename T>
class Node{
    public:
    T val;
    int idex;
    Node<T>* next;
    Node<T>* prev;
    Node(T val):val(val),idex(0),next(nullptr),prev(nullptr){};
};
template <typename T>
class Doubly_LL{
    Node<T>* head;
    Node<T>* tail;
    int count ;
    public:
    Doubly_LL():head(nullptr),tail(nullptr),count(0){};
    void reindx(){
        Node<T>* temp = head;
        int idx = 0 ;
        while(temp != nullptr){
            temp->idex = idx;
            idx++;
            temp = temp->next;
        }
    }
    ~Doubly_LL(){
        while(head != nullptr){
            Node<T>* next = head->next;
            delete head;
            head = next;
        }
        head= nullptr;
        tail = nullptr;
        count = 0;
    }
    void insert(T val){
        Node<T>* newNode = new Node<T>(val);
        if(count == 0){
            head =newNode;
            tail = newNode;
            count++;
            reindx();
            return;
        }
        tail->next =newNode;
        newNode->prev =tail;
        tail = newNode;
        count++;
        reindx();
    }
    Doubly_LL(const Doubly_LL<T>& list){
        head = nullptr;
        tail = nullptr;
        count = 0;
        Node<T>* temp = list.head;
        while(temp != nullptr){
            insert(temp->val);
            temp = temp->next;
        }
    }
    Doubly_LL<T>& operator=(Doubly_LL<T> list){
        if(head != nullptr){
            while(head != nullptr){
                Node<T>* next = head->next;
                delete head;
                head = next;
            }
        head= nullptr;
        tail = nullptr;
        count = 0;
    }
    Node<T>* temp = list.head;
        while(temp != nullptr){
            insert(temp->val);
            temp = temp->next;
        }
        return *this;
    }
    void inserthead(T val){
        Node<T>* newNode = new Node<T>(val);
        if(count == 0){
            head = newNode;
            tail = newNode;
            count++;
            reindx();
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head =newNode;
        count++;
        reindx();
    }
    void inert_after(T val , int i){
        Node<T>*newNode = new Node<T>(val);
        Node<T>*temp = head;
        while(temp->idex != i){
            temp =temp->next;
        }
        if(temp == tail){
            delete newNode;
            insert(val);
            return;
        }
        temp->next->prev = newNode;
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        count++;
        reindx();
        return;
    }
    void deleteNode(int i){
        Node<T> *temp = head;
        while(temp->idex != i ){
            temp = temp->next;
        } 
        if(temp == head){
            head->next->prev = nullptr;
            head =  temp->next;
            delete temp;
            count--;
            reindx();
            return;
        }
        if(temp == tail){
            tail->prev->next =nullptr;
            tail = temp->prev;
            delete temp;
            count--;
            reindx();
            return;
        }
        temp->next->prev =temp->prev;
        temp->prev->next = temp->next;
        delete temp;
        count--;
        reindx();
    }
    T search(int i){
        Node<T>* temph = head;
        Node<T>* templ = tail;
        while(temph->idex != i && templ->idex != i){
            temph = temph->next;
            templ = templ->prev;
        }
        if(temph->idex==i)return temph->val;
        return templ->val;
    }
    void input(){
        T val;
        char choice;
        do{
            cout<<"Enter the element : "<<endl;
            cin >> val;
            insert(val);
            cout<<"Enter x if you want to exit : "<<endl; 
            cin >> choice;
        }while(choice != 'x');
    }
    void display(){
        for(int i = 0 ; i < count ; i++){
            cout << search(i) << "->";
        }
        cout <<endl;
    }
    int getcount(){
        return count;
    }
};