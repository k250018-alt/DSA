#include"iostream"
#include"random"
#include"Doubly_LL.h"
using namespace std;
struct Legend{
    string name;
    int health;
    int attack;
    ~Legend(){
        cout << name <<" Has been defeated "<< endl;
    }
};
int randInt(int min , int max){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(min,max);
    return dist(gen);
}
ostream& operator<<(ostream& os ,const Legend &l){
    os << l.name << " : " << l.health << " : "<<l.attack;
    return os;
}
istream& operator>>(istream& is , Legend &l){
    is >> l.name;
    l.health = randInt(1 , 70);
    l.attack = randInt(1,5);
    return is;
}
void check_for_deaths(Doubly_LL<Legend>& list ){
    for(int i = 0 ; i < list.getcount() ; i++){
        if(list.search(i).health <= 0){
            list.deleteNode(i);
            i--;
        }
    }
}
void attack(Doubly_LL<Legend>& list1 ,Doubly_LL<Legend>& list2 , int posdefending ,int posattacking){
    if(posattacking > list1.getcount()-1 || posattacking < 0 || posdefending > list2.getcount()-1 || posdefending < 0){
        cout << "Invalid pos "<<endl;
        return;
    }
    else{
       int damage  = list1.search(posattacking).attack * randInt(1,3);
       list2.search(posdefending).health = list2.search(posdefending).health -damage;
       return ; 
    }
    return ;
}
int main(){
    Doubly_LL<Legend> hero_legends;
    cout << "Enter you heros" <<endl;
    do{
        hero_legends.input();
    }while(hero_legends.getcount() < 5);
    Doubly_LL<Legend> monsters;
    for(int i = 0 ; i< hero_legends.getcount() ; i++){
        Legend enemy = {"Monster" , randInt(1,70),randInt(1,5)};
        monsters.insert(enemy);
    }
    int attackpos;
    int defensepos;
    do{
        cout<< "Enemy"<<endl;
        monsters.display();
        cout<<endl;
        cout<<endl;
        cout<<endl;
        hero_legends.display();
        cout <<"Your legends "<<endl;
        cout<<endl;
        cout << "What pos so you want to attack :"<<endl;
        cin >> defensepos;
        cout << "From which monster do you want to attack :"<<endl;
        cin >> attackpos;
        attack(hero_legends, monsters ,defensepos,attackpos);
        attackpos =randInt(0,monsters.getcount()-1);
        defensepos =randInt(0,hero_legends.getcount()-1);
        attack(monsters,hero_legends,defensepos,attackpos);
    }while(hero_legends.getcount() != 0 && monsters.getcount() != 0 );
    if(hero_legends.getcount() == 0){
        cout << "HAHA! FUCKIN LOSER LOST TO RANDOM INPUTS"<<endl;
    }else{
        cout << "CONGRATULATION YOU WON AGAINST COMPLETE RANDOM INPUTS"<<endl;
    }
}