//the alogrithm is taht is being described here is insersion sort
#include "iostream"
using namespace std;

void insersion_sort(int *arr, int n){
    for(int i = 1 ; i < n ; i++){
        int key = arr[i];
        int  j = i-1 ;
        while(j>= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
void print(int *arr , int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " | ";
    }
}
int main(){
    int arr[6] = {85, 42, 120, 35, 67, 50};
    insersion_sort(arr,6);
    print(arr,6);
}