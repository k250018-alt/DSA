#pragma once
#include "iostream"
using namespace std;
template <typename T>
class Plate{
    public:
    T val;
    Plate<T> *below;
    Plate(T v ):val(v),below(nullptr){};
};
template <typename T>
class Stack{
    Plate<T>* top;
    public:
    Stack():top(nullptr){};
    void push(T val){
        Plate<T>* newPlate = new Plate<T>(val);
        newPlate->below =top;
        top = newPlate;
    }   
    ~Stack(){
        while(!isEmpy()){
            pop();
        }
    }
    bool isEmpy(){
        return top == nullptr;
    }
    T peek(){
        if(!top){
            cout << "nothing in the stack"<<endl;
            return T();
        }
        else{
            return top->val;
        }
    }
    void pop(){
        if(!top){
            cout << "Stack underflow"<<endl;
            return;
        }
        Plate<T>* temp = top;
        top = top->below;
        delete temp;
    }
};