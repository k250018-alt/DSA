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
template <typename T>
class Circ_sll{
    int count;
    Node<T> *head;
    public:
    Circ_sll():head(nullptr) ,count(0){}
    ~Circ_sll(){
        if(head == nullptr) return;
        Node<T> *temp = head;
        do{
            Node<T> *next = temp->next;
            delete temp;
            temp = next;
        }while(temp != head);
    }
    Circ_sll(Circ_sll& list){
        head = nullptr;
        count =0;
        if(list.head == nullptr) return;
        Node<T> *temp = list.head;
        do{
            insert(temp->num);
            temp = temp->next;
        }while(temp != list.head);
    }
    Circ_sll& operator =(Circ_sll list){
        if(this->head){
            Node<T> *temp = head;
            do{
                Node<T> *next = temp->next;
                delete temp;
                temp = next;
            }while(temp != head);
            
    }   head = nullptr;
        count =0;
        if(list.head == nullptr) return *this;
        Node<T> *temp = list.head;
        do{
            insert(temp->num);
            temp = temp->next;
        }while(temp != list.head);
        return *this;
    }
    void reindx(){
        if(head == nullptr) return;
        Node<T> *temp = head;
        int idx = 0;
        do{
            temp->index= idx;
            temp =temp->next;
            idx++;
        }while(temp != head);
    }
    void insert(T value){
        Node<T> *newNode = new Node<T>(value);
        if(head == nullptr){
            head = newNode;
            head->next = head;
            count++;
            reindx();
            return;
        }
        Node<T> *temp = head; 
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        count++;
        reindx();
    }
    void inserthead(T value ){
        Node<T> *newNode = new Node<T>(value);
        if(head == nullptr){
            head = newNode;
            head->next = head;
            count++;
            reindx();
            return;
        }
        Node<T> *temp =head;
        do{
            temp =temp->next;
        }while(temp->next != head);
        temp->next = newNode;
        newNode->next =head;
        head = newNode;
        count++;
        reindx();
    }
    void inserinbetween(T value , int i){
        if(head == nullptr) return;
        if(i < 0 || i >= count) return;
        Node<T> *newNode = new Node<T>(value);
        Node<T>* temp = head;
        while(temp->index != i){
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        count++;
        reindx();
    }
    T serach(int i){
        Node<T>* temp = head;
        while(temp->index != i){
            temp =temp->next;
        }
        return temp->num;
    }
    void delete_head(){
        if(head == nullptr) return;
        if(head->next == head){
            delete head;
            head = nullptr;
            count= 0;
            return;
        }
        Node<T> *temp= head;
        while(temp->next != head ){
            temp =temp->next;
        }
        temp->next = head->next;
        delete head;
        head = temp->next;
        count--;
        reindx();
    }
    void delete_tail(){
        if(head == nullptr) return;
        if(head->next == head){
            delete head;
            head = nullptr;
            count= 0;
            return;
        }
        Node<T> *temp = head;
        Node<T>* prev =nullptr;
        while(temp->next != head){
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        delete temp;
        count--;
        reindx();
    }
    void delete_node(int i){
        if(head == nullptr) return;
        if(i < 0 || i >= count) return;
        if(count == 1){
            delete head;
            head =nullptr;
            count = 0;
            return;
        }
        Node<T>* temp = head;
        Node<T> *before = nullptr;
        if(i == 0){
            before = head;
            while(before->next != head){
                before = before->next;
            }
            head = head->next;
            before->next = head;
        }else{
            while(temp->index != i){
                before = temp;
                temp =temp->next;
            }
        before->next = temp->next;
    }
        delete temp;
        count--;
        reindx();
    }
    void display(){
        for(int i =0 ; i < count ; i++){
            cout << serach(i) << "->" ; 
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
    int get_count(){
        return count;
    }
};