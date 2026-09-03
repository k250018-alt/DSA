#include "iostream"
using namespace std;

class Student_Database{
    int marks[10];
    float average;
    int highest;
    int lowest;
    int len = sizeof(marks)/sizeof(int);
    int *above_avg = nullptr;
    int count = 0;
    public:
    Student_Database():marks{23 , 42 , 34, 53 ,56, 77, 54, 54,97 ,76},average(0),highest(0),lowest(0){
    }
    void find_averae(){
        int total  =0 ;
        for(int i = 0; i < len ; i++){
            total +=marks[i];
        }
        average = static_cast<float> (total)/len;
    }
    int* resize(int *arr , int oldlen,int n){
        int* newarr = new int[n];
        for(int i = 0 ; i < oldlen ; i++){
            newarr[i] = arr[i];
        }
        delete[] arr;
        return newarr;
    }
    void find_aboveavg(){
        for(int i = 0 ; i < len ; i++){
            if(marks[i] >= average){
                int previousCount = count;
                count++;
                above_avg = resize(above_avg, previousCount, count);
                above_avg[count-1] = marks[i];
            }
        }
    }
    void highest_lowest_bubblesort(){
        for( int i = 0 ; i < len ; i++){
            bool swaps = true;
            for(int j = 0; j < len - i - 1 ; j++){
                if(marks[j] > marks[j+1]){
                    int temp = marks[j];
                    marks[j] =marks[j+1];
                    marks[j+1] = temp;
                    swaps = false;
                }
            }
            if (swaps){
                break;
            }
        }
        highest = marks[len-1];
        lowest =marks[0];
    }
    void display(){
        cout << "  Marks  "<<endl;
        for(int i =0 ; i < len ; i++){
            cout << marks[i] << " , ";
        }
        cout << endl << " AVerage " << endl << average <<endl;
        cout<< "Above average" << endl;
        for(int i =0 ; i < count ; i++){
            cout << above_avg[i] << " , ";
        }
        cout << endl << " Highest " << endl << highest <<endl << " Lowest " << endl << lowest;
    }
    ~Student_Database(){
        delete[]above_avg;
    }
};
int main(){
    Student_Database s1;
    s1.find_averae();
    s1.find_aboveavg();
    s1.highest_lowest_bubblesort();
    s1.display();
}