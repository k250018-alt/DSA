#include "iostream"
#include "string"
using namespace std;
struct JOBS
{
    string job_name;
    int rank;
};
void display(JOBS* arr ,int size){
    for(int i =0 ; i < size ; i++ ){
        cout << arr[i].rank << ")" << arr[i].job_name<<endl;
    }
}
void copy_arr(JOBS* arr , JOBS* arr1,int size){
    for(int i = 0 ; i < size ; i++){
        arr[i]=arr1[i];
    }
}
void compsort(JOBS *arr, int size)
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
            if (arr[j].job_name > arr[j + gap].job_name)
            {
                JOBS temp = arr[j + gap];
                arr[j + gap] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }
    }
}
int binary_search(JOBS *arr, int size, string searched)
{
    compsort(arr,size);
    int low = 0;
    int high = size - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (searched == arr[mid].job_name)
        {
            return mid;
        }
        if (searched > arr[mid].job_name)
        {
            low = mid + 1;
        }
        if (searched < arr[mid].job_name)
        {
            high = mid - 1;
        }
    }
    return -1;
}

void rank_arr(JOBS *arr ,int size){
    display(arr,size);
    string searched;
    int temp;
    for(int i =0 ; i < size ; i++){
        cout << "Rank the " << i+1 <<" prioty job "<<endl;
        getline(cin,searched);
        temp = binary_search(arr,size,searched);
        if(temp == -1){
            cout << "wrong serach moving to the next rank"<<endl;
            continue;
        }
        arr[temp].rank = i+1;
     }
}
void  main_menu(){
    int choice;
    JOBS* arr;
    char a;
    string reason;
    cout << "What do you chose "<<endl;
    cout << "1) Industry"<<endl;
    cout << "2) Academia"<<endl;
    cout << "Do you need more explanation"<<endl;
    cin >> a;
    if (a == 'y'){
        cout << "Academia offers the freedom to pursue deep, curiosity-driven research over a long time horizon, while industry offers faster feedback loops, larger resources, and the chance to see your work directly shape real products used by millions"<<endl;
    }
    cout<<"What do you chose"<<endl;
    cin >> choice;
    switch(choice){
        case 1:{
            cout << "Enter a reason to chose industy :"<<endl;
            cin >>reason;
            arr = new JOBS[9];
            JOBS jobsList[9] = {
                {"AI Engineer", 0},
                {"Software Engineer", 0},
                {"Data Scientist", 0},
                {"Machine Learning Engineer", 0},
                {"DevOps Engineer", 0},
                {"Data Engineer", 0},
                {"Cybersecurity Engineer", 0},
                {"Project Manager", 0},
                {"Cloud Engineer", 0}
            };
        copy_arr(arr,jobsList,9);
        rank_arr(arr,9);
        delete[] arr;
        break;
    }case 2:{
        cout << "Enter a reason to chose academia :"<<endl;
        cin >>reason;
        arr = new JOBS[5];
        JOBS jobsList[5] = {
            {"Lecturer", 0},
            {"Research Scientist", 0},
            {"Academic Researcher", 0},
            {"PhD Researcher", 0},
            {"Research Assistant", 0}
            };
        copy_arr(arr,jobsList,5);
        rank_arr(arr,5);
        delete[] arr;
        break;
    }
    default:{
        cout<<"Chosing industry as default :"<<endl;
        arr = new JOBS[9];
            JOBS jobsList[9] = {
                {"AI Engineer", 0},
                {"Software Engineer", 0},
                {"Data Scientist", 0},
                {"Machine Learning Engineer", 0},
                {"DevOps Engineer", 0},
                {"Data Engineer", 0},
                {"Cybersecurity Engineer", 0},
                {"Project Manager", 0},
                {"Cloud Engineer", 0}
            };
        copy_arr(arr,jobsList,9);
        rank_arr(arr,9);
        delete[] arr;
        break;
    }
}}
int main(){
    main_menu();
}