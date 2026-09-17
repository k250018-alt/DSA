#pragma once
#include "iostream"
using namespace std;
int maxsize = 20; 
template <typename T>
class Queue{
    T* arr;
    int first;
    int last;
    int count;
    public:
    bool EmptyQueue(){
        return count == 0;
    }
    bool QueueFull(){
        return count == maxsize;
    }
    Queue():first(0),last(0),count(0){
        arr = new T[maxsize];
    }
    ~Queue(){
        delete[] arr;
    }
    void enque(T val){
        if(count == maxsize){
            cout << "maxsize reached";
        }else{
            arr[last%maxsize] = val;
            last++;
            count++;
        }
    }
    void deque(){
        if(count == 0){
            cout << "Nothing in Queue";
        }else{
            first++;
            count--;
        }
    }
    T& frontref(){
        return arr[first%maxsize];
    }
    T front(){
        return arr[first%maxsize];
    }
};