#include"iostream"
#include"Queue.h"
using namespace std;

struct Patient{
    string name;
    int condion;
    Patient():name("unknown"),condion(0){};
};
void treat(Queue<Patient>& queue){
    cout << queue.front().name << " is being treated \n";
    queue.deque();
}
void manageQueues(Queue<Patient>& critical , Queue<Patient>& serious ,Queue<Patient>& normal){
    if(!critical.EmptyQueue()){
        treat(critical);
    }else if(!serious.EmptyQueue()){
        treat(serious);
    }else if(!normal.EmptyQueue()){
        treat(normal);
    }else{
        cout <<"ALL patient treated";
    }
}
int main(){
    char choice;
    Patient P;
    Queue<Patient> critical;
    Queue<Patient> serious;
    Queue<Patient> normal;
    do{
        cout << "Enter the Patient info";
        cin >> P.name;
        cout << "Enter the condition of patient";
        cin >> P.condion;
        switch(P.condion){
            case 1:
                normal.enque(P);
                break;
            case 2:
                serious.enque(P);
                break;
            case 3:
                critical.enque(P);
                break;
            default:
                normal.enque(P);
        }
        cout << "Do you want to add more patients";
        cin >> choice;
    }while(choice != 'x');
    while(!normal.EmptyQueue()){
        manageQueues(critical,serious,normal);
    }
}