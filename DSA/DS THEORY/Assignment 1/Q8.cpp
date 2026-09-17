#include "iostream"
#include "Stack.h"
using namespace std;
void undo(Stack<char> &stack){
    if(stack.isEmpy()){
        cout << "No command to undo "<<endl;
        return;
    }
    char choice = stack.peek();
    switch(choice){
            case 'R':
                cout <<"moving one to the left\n";
                stack.pop();
                break;
            case 'L':
                cout <<"moving one position to the  right\n";
                stack.pop();
                break;
            case 'J':
                cout <<"moving two position to the left\n";
                stack.pop();
                break;
            }
}
void game(){
    char choice;
    Stack<char> stack;
    do{
        cout << "Enter the action you want to perfrom\n";
        cin >>choice;
        switch(choice){
            case 'R':
                cout <<"moving one to the right\n";
                stack.push('R');
                break;
            case 'L':
                cout <<"moving one position to the left\n";
                stack.push('L');
                break;
            case 'J':
                cout <<"moving two position to the right\n";
                stack.push('J');
                break;
            case 'B':
                undo(stack);
                break;
            case 'X':
                cout <<"exiting";
                break;
            default:
                cout << "Invalid";
                break;
        }
    }while(choice != 'X');
}
int main(){
    game();
}