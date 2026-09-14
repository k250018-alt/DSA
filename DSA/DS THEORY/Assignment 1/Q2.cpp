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
    cout << endl;
}
int* resize(int *oldarr , int n , int add ,int pos){
    int* newarr = new int[n+1];
    int current =0;
    for(int i = 0 ; i < n+1 ; i++){
        if(i == pos){
            newarr[i] = add; 
            continue;;
        }
        newarr[i] = oldarr[current];
        current++;
    }
    insersion_sort(newarr,n+1);
    return newarr;
}
void copyarr(int *arr ,int* copyfrom, int n){
    for(int i =0 ; i< n ;i++){
        arr[i] = copyfrom[i];
    }
}
int main(){
    int *shelves =new int[6] ;
    int arr[6] = {85, 42, 120, 35, 67, 50};
    copyarr(shelves,arr,6);
    insersion_sort(shelves,6);
    print(shelves,6);
    shelves = resize(shelves,6,76,3);
    print(shelves,7);
}