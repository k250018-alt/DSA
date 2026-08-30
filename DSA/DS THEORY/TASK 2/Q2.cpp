#include "iostream"
using namespace std;

struct Employee{
    string job;
    int priority;
};

Employee* insertion_sort(Employee* arr , int size){
    for(int i = 1 ; i < size ; i++){
        Employee key = arr[i];
        int j = i -1;
        while(j >= 0 && arr[j].priority >key.priority){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    return arr;
}
void print(Employee *arr , int size ){
    for(int i =size-1 ; i >= 0;i--){
        cout << arr[i].job <<endl;
    }
}
int main(){
    Employee arr[8] = {
        {"EMP", 1},
        {"CFO", 4},
        {"MGR", 2},
        {"EMP", 1},
        {"VP", 3},
        {"CTO", 5},
        {"MGR", 2},
        {"CEO", 6}
    };
    insertion_sort(arr,8);
    print(arr,8);
}