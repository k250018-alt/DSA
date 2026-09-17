#include "iostream"
#include "Stack.h"
#include "Queue.h"
struct Player{
    int ID;
    int  energy;
    Stack<char> stack;
    Player(int Id):ID(Id),energy(100){};
};
void undo(Player &p){
    if(p.stack.isEmpy()){
        cout << "no previous instruction";
        return;
    }
    char choice =p.stack.peek();
    switch(choice){
        case 'F':
            cout << "moving forward"<<endl;
            p.energy+=10;
            p.stack.pop();
            break;
        case 'B':
            cout << "moving backwards"<<endl;
            p.stack.pop();
            break;
        case 'T':
            cout << "decarding treasure"<<endl;
            p.energy -=20;
            p.stack.pop();
            break;
    }
}
void choice(Player& p){
    char choice;
    cout << "What do you want to do with "<< p.ID;
    cin >> choice;
    switch(choice){
        case 'F':
            cout << "moving forward"<<endl;
            p.energy-=10;
            p.stack.push('F');
            break;
        case 'B':
            cout << "moving backwards"<<endl;
            p.stack.push('B');
            break;
        case 'T':
            cout << "collecting treasure"<<endl;
            p.energy +=20;
            p.stack.push('T');
            break;
        case 'U':
            cout << "Undoing the previous choice"<< endl;
            undo(p);
            break;
        default:
            cout << "invalid";
    }
}
void game(){
    Queue<Player> queue;
    int id =0;
    while(!queue.QueueFull()){
        Player p(id);
        queue.enque(p);
        id++;
    }
    while(!queue.EmptyQueue()){
        choice(queue.frontref());
        if(queue.front().energy <= 100){
            cout << queue.front().ID << "deleted";
            queue.deque();
        }
    }
}
int main(){
    game();
}