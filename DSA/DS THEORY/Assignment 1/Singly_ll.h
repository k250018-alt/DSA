#pragma once
#include "iostream"
using namespace std;
template <typename T>
class Node{
    public:
    T num;
    Node<T>* next;
    int index;
    Node(T num):num(num),next(nullptr),index(0){}
};
template<typename T>
class Singly_LL{
    Node<T>* head;
    int count;
    public:
    Singly_LL():head(nullptr),count(0){}
    int get_count(){
        return count;
    }
    void reindx(){
        Node<T> *temp = head;
        int idx = 0;
        while(temp != nullptr){
            temp->index = idx;
            temp = temp->next;
            idx++;
        }
    }
    ~Singly_LL(){
        Node<T> *cur =head;
        while(cur != nullptr){
            Node<T> *next = cur->next;
            delete cur;
            cur = next;
        }
    }
    Singly_LL(Singly_LL<T> &lst){
        head = nullptr;
        count = 0;
        Node<T> *temp = lst.head;
        while(temp != nullptr){
            insert(temp->num);
            temp = temp->next;
        }
    }
    Singly_LL<T>& operator =(Singly_LL<T> lst){
        Node<T> *cur =head;
        while(cur != nullptr){
            Node<T> *next = cur->next;
            delete cur;
            cur = next;
        }
        head = nullptr;
        count = 0;
        Node<T> *temp = lst.head;
        while(temp != nullptr){
            insert(temp->num);
            temp = temp->next;
        }
        return *this;
    }
    void insert(T val){
        Node<T> *newNode = new Node<T>(val);
        if(count == 0){
            head = newNode;
            count++;
            reindx();
            return;

        }
        Node<T>* temp =head;
        while(temp->next != nullptr){
            temp =temp->next;
        }
        temp->next = newNode;
        count++;
        reindx();
    }
    void inserthead(T val){
        Node<T> *newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
        count++;
        reindx();
    }
    void insertinbetween(T val,int i ){
        Node<T> *newNode = new Node<T>(val);
        Node<T> *temp = head;
        while(temp->index != i){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        count++;
        reindx();
    }
    T search_Node(int i){
        Node<T> *temp= head;
        while(temp->index != i){
            temp = temp->next;
        }
        return temp->num;
    }
    void delete_node(int i){
        Node<T> *temp = head;
        Node<T> *before = nullptr;
        while(temp->index != i ){
            before =temp;
            temp = temp->next;
        }
        if(before == nullptr){
            head = temp->next;
        }else{
            before->next = temp->next;
        }
        delete temp;
        count--;
        reindx();
    }
    void display(){
        for(int i =0 ; i < count ; i++){
            cout << search_Node(i) << "->" ; 
        }
        cout<<endl;
    }
    void input(){
    T num;
    char choice;
    do{
      
      cout << "Enter a value:" <<endl;
      cin >> num;
      insert(num);
      cout << "Enter x to finish list" << endl;
      cin>> choice;
    }while(choice != 'x');
    }
};