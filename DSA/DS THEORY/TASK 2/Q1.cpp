#include"iostream"
using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

bool byDateFull(Date a, Date b) {
    if (a.year != b.year) return a.year < b.year;
    if (a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}

Date* selection_sort(Date* arr ,int start, int size ,bool (*compare)(Date,Date)){
    for(int i  = start; i < size ; i++){
        int minimum = i;
        for(int j = i+1 ;  j < size ; j++){
            if (compare(arr[j],arr[minimum])){
                minimum = j;
            }
        }
        Date temp = arr[i];
        arr[i] =arr[minimum];
        arr[minimum] =temp;
    }
    return arr;
}

void print(Date *arr , int size ){
    for(int i = 0 ; i < size ; i++){
        cout << arr[i].day << "/"<<  arr[i].month << "/" << arr[i].year<<endl;
    }
}
int main(){
    Date* arr_of_date = new Date[5];
    for(int i = 0 ; i < 5 ; i++){
        cout << "Enter a date " <<endl << "enter the date" << endl;
        cin >> arr_of_date[i].day;
        cout << "Enter the month"<<endl;
        cin >> arr_of_date[i].month;
        cout << "Enter the year"<<endl;
        cin >>arr_of_date[i].year;
    }
   
    int len= 5;
    print(arr_of_date,len);
    arr_of_date = selection_sort(arr_of_date,0,len ,byDateFull);
    print(arr_of_date,len);
}

