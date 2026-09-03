#include"iostream"
using namespace std;

struct classe{
    int codes;
    string teacher_name;
    int time;
};
classe linear_search(classe *arr, int size, int searched)
{
    int j =0;
    bool found = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].codes == searched)
        {
            cout<< "loops :"<< i <<endl;
            return arr[i];
        }
        j=i;
    }
    cout<< "loops :"<< j <<endl;
    classe temp = {0,"Not found", 0};
    return temp;
}
classe binary_search(classe *arr, int size, int searched)
{
    int i=0;
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (searched == arr[mid].codes)
        {
            cout<< "loops :"<< i <<endl;
            return arr[mid];

        }
        if (searched > arr[mid].codes)
        {
            low = mid + 1;
        }
        if (searched < arr[mid].codes)
        {
            high = mid - 1;
        }
        i++;
    }
    cout<< "loops :"<< i <<endl;
    classe temp = {0,"Not found", 0};
    return temp;
}
classe interpolationSearch(classe* arr, int n, int key){
    int i=0;
    int low = 0;
    int high = n - 1;
    while (low <= high && key >= arr[low].codes && key <= arr[high].codes)
    {
        if (arr[low].codes == arr[high].codes)
        {
            if (arr[low].codes == key){
                cout<< "loops :"<< i <<endl;
                return arr[low];}
            classe temp = {0,"Not found", 0};
            cout<< "loops :"<< i <<endl;
            return temp;
        }
    int pos = low + ((key - arr[low].codes) * (high - low) / (arr[high].codes - arr[low].codes));
    if (arr[pos].codes == key){
            cout<< "loops :"<< i <<endl;
            return arr[pos];
        }
    else if (arr[pos].codes < key){
            low = pos + 1;
        }
    else{
            high = pos - 1;
        }
        i++;
    }
    cout<< "loops :"<< i <<endl;
    classe temp = {0,"Not found", 0};
    return temp;
}
int main(){
    classe unsorted_arr[8] = {
        {305, "Ahmed", 45},
        {102, "Sara", 60},
        {450, "Kashif", 30},
        {210, "Ali", 90},
        {150, "Zain", 15},
        {380, "Fatima", 75},
        {120, "Bilal", 50},
        {290, "Hina", 40}
    };
    classe sorted_arr[8] = {
        {102, "Sara", 60},
        {120, "Bilal", 50},
        {150, "Zain", 15},
        {210, "Ali", 90},
        {290, "Hina", 40},
        {305, "Ahmed", 45},
        {380, "Fatima", 75},
        {450, "Kashif", 30}
    };
    classe uniform_arr[8] = {
        {100, "Sara", 60},
        {150, "Bilal", 50},
        {200, "Zain", 15},
        {250, "Ali", 90},
        {300, "Hina", 40},
        {350, "Ahmed", 45},
        {400, "Fatima", 75},
        {450, "Kashif", 30}
    };
    cout<<"Unsorted array"<<endl;

    cout<<"Linear search"<<endl;
    linear_search(unsorted_arr,8,380);//only this can work on unsorted arrays
    
    cout<<"Sorted array"<<endl;

    cout<<"Linear search"<<endl;
    linear_search(sorted_arr,8,380);
    cout<<"Binary search"<<endl;
    binary_search(sorted_arr,8,380);//best for sorted array
    cout << "Intoploration search" <<endl;
    interpolationSearch(sorted_arr,8,380);

    cout<<"Uniforermly sorted array"<<endl;

    cout<<"Linear search"<<endl;
    linear_search(uniform_arr,8,350);
    cout<<"Binary search"<<endl;
    binary_search(uniform_arr,8,350);
    cout << "Intoploration search" <<endl;
    interpolationSearch(uniform_arr,8,350);//best for uniformerly sorted array

}