#include "iostream"
using namespace std;

void compsort(int*arr , int size){
    int gap =size;
    bool swapped = true;
    int swaps = 0;
    int passes =0;
    while(gap > 1 || swapped){
        gap /= 1.6;//1.3 did the job in 6 passes while 1.6 does the job in 4 passes so it is clearly better
        if(gap < 1) gap = 1;
        swapped =false;
            for(int j = 0 ; j < size-gap ; j++){
                if(arr[j] > arr[j+gap]){
                    int temp = arr[j+gap];
                    arr[j+gap] = arr[j];
                    arr[j] = temp;
                    swapped =true;
                    swaps ++;
                }
            }
        passes++;
    }
    cout << passes <<endl;
    cout << swaps << endl;

}
void print(int *arr ,int size){
    for(int i = 0 ; i < size ; i++){
        cout << arr[i] <<endl;
    }
}
int main(){
    int products_prices[8]  = {170 ,45 ,75,90 ,802,2,25,66};
    compsort(products_prices,8);
    print(products_prices,8);
}