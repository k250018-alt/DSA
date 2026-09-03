#include "iostream"
using namespace std;
const int minimum =7;
const int maximum =20;
struct Activities
{
    string activity_name;
    int time_spent;
};
void bubblesort(Activities *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        bool swaps = true;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j].time_spent > arr[j + 1].time_spent)
            {
                Activities temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps = false;
            }
        }
        if (swaps)
        {
            break;
        }
    }
}
void selection_sort(Activities *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        int minimum = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j].time_spent < arr[minimum].time_spent)
            {
                minimum = j;
            }
        }
        Activities temp = arr[i];
        arr[i] = arr[minimum];
        arr[minimum] = temp;
    }
}
void insertion_sort(Activities *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        Activities key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].time_spent > key.time_spent)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void compsort(Activities *arr, int size)
{
    int gap = size;
    bool swapped = true;
    while (gap > 1 || swapped)
    {
        gap /= 1.3;
        if (gap < 1)
            gap = 1;
        swapped = false;
        for (int j = 0; j < size - gap; j++)
        {
            if (arr[j].time_spent > arr[j + gap].time_spent)
            {
                Activities temp = arr[j + gap];
                arr[j + gap] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }
    }
}
void shellSort(Activities* arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            Activities temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap].time_spent > temp.time_spent)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}
Activities linear_search(Activities *arr, int size, string searched)
{
    bool found = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].activity_name == searched)
        {
            return arr[i];
        }
    }
    Activities temp = {"Not found", 0};
    return temp;
}
Activities binary_search(Activities *arr, int size, string searched)
{
    compsort(arr, size);
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (searched == arr[mid].activity_name)
        {
            return arr[mid];
        }
        if (searched > arr[mid].activity_name)
        {
            low = mid + 1;
        }
        if (searched < arr[mid].activity_name)
        {
            high = mid - 1;
        }
    }
    Activities temp = {"Not found", 0};
    return temp;
}
Activities interpolationSearch(Activities* arr, int n, int key){
    compsort(arr,n);
    int low = 0;
    int high = n - 1;
    while (low <= high && key >= arr[low].time_spent && key <= arr[high].time_spent)
    {
        if (arr[low].time_spent == arr[high].time_spent)
        {
            if (arr[low].time_spent == key)
                return arr[low];
            Activities temp = {"Not found", 0};
            return temp;
        }
    int pos = low + ((key - arr[low].time_spent) * (high - low) / (arr[high].time_spent - arr[low].time_spent));
    if (arr[pos].time_spent == key){
            return arr[pos];
        }
    else if (arr[pos].time_spent < key){
            low = pos + 1;
        }
    else{
            high = pos - 1;
        }
    }
    Activities temp = {"Not found", 0};
    return temp;
}
void display_search(Activities act ){
    if(act.activity_name == "Not found"){
        cout << "Activity not found"<<endl;
        return;
    }
    cout << "Activity found : "<< act.activity_name<<endl;
    cout << "DO you want to see the time (y/n):"<<endl; 
    char choice;
    cin >> choice;
    if(choice =='y'){
        cout << "Activity found : "<< act.activity_name<<endl;
        cout << "Time spent on activity "<< act.time_spent<<endl;
    }
}
void input(Activities* arr ,int size){
    for(int i =  0 ; i < size ; i++ ){
        cout << "Eneter the activities name :"<< endl;
        cin >> arr[i].activity_name;
        cout << "Enter the actvity time spent :"<<endl;
        cin >> arr[i].time_spent;
    }
}
void display(Activities* arr ,int size){
    for(int i =0 ; i < size ; i++ ){
        cout << "Activity name :" << arr[i].activity_name <<endl;
    }
    cout << "Do you wnat to see the time also (y/n)"<<endl;
    char choice ;
    cin >> choice;
    if(choice == 'y'){
        for(int i =0 ; i < size ; i++ ){
        cout << "Activity name :" << arr[i].activity_name <<endl;
        cout << "Activity time :" << arr[i].time_spent <<endl;
    }
    }
}
void main_menu(){
    cout <<"Enter the number activities (minimum 7 and max 20)" << endl;
    int size;
    cin >> size;
    if(size < minimum)size = minimum;
    if(size > maximum)size =maximum;
    Activities *arr = new Activities[size];
    input(arr,size);
    int choice =0;
    cout << "========SORTING======="<<endl;
    cout <<"Enter which sorting alogrithm you want to use"<<endl;
    cout << "1) Bubble sort"<<endl;
    cout << "2) Insertion sort"<<endl;
    cout << "3) Shelll sort"<<endl;
    cout << "4) Selection sort"<<endl;
    cout << "5) Comb sort"<<endl;
    cin >> choice;
    switch(choice){
        case 1:
        bubblesort(arr,size);
        display(arr,size);
        break;
        case 2:
        insertion_sort(arr,size);
        display(arr,size);
        break;
        case 3:
        shellSort(arr,size);
        display(arr,size);
        break;
        case 4:
        selection_sort(arr,size);
        display(arr,size);
        break;
        case 5:
        compsort(arr,size);
        display(arr,size);
        break;
        default:
        cout <<"Invalid input using comb sort";
        compsort(arr,size);
        display(arr,size);
        break;
    }
    cout << "======SEARCHING======"<<endl;
    cout <<"Enter which searching alogrithm you want to use"<<endl;
    cout << "1) Linear search"<<endl;
    cout << "2) Binary search"<<endl;
    cout << "3) Interpolation search"<<endl;
    choice =0;
    cin >> choice;
    string searching;
    int search;
    Activities act;
    switch(choice){
        case 1:
        cout << "Enter the name of the activity :" <<endl;
        cin >>searching;
        act = linear_search(arr,size,searching);
        display_search(act);
        break;
        case 2:
        cout << "Enter the name of the activity :" <<endl;
        cin >>searching;
        act = binary_search(arr,size,searching);
        display_search(act);
        break;
        case 3:
        cout << "Enter the time spent on the activity :" <<endl;
        cin >>search;
        act = interpolationSearch(arr,size,search);
        display_search(act);
        break;
        default:
        cout<<"invalid input usin binary search"<<endl;
        cout << "Enter the name of the activity :" <<endl;
        cin >>searching;
        act = binary_search(arr,size,searching);
        display_search(act);
        break;
    }
    delete[] arr;
}
int main(){
    main_menu();
}