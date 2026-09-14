#include"iostream"
using namespace std;

void compsort(int* arr ,int n){
    int gap = n;
    bool swapped =true;
    while(gap > 1 && swapped){
        gap /= 1.3;
        if(gap < 1){
            gap = 1;
        }
        for(int i = 0 ; i < n -gap ; i++){
            if(arr[i] > arr[i+gap]){
                int temp = arr[i+gap];
                arr[i+gap] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
void print(int *arr , int n){
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " | ";
    }
    cout << endl;
}
int main(){
    int arr[8] = {120, 35, 90,15, 75, 10, 60, 25};
    print(arr,8);
    compsort(arr,8);
    print(arr,8);
}