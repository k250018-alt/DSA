#include"iostream"
using namespace std;

class BankAccount{
    string *name;
    float *balance;
    public:
    BankAccount(){
        name = new string("unknown");
        balance = new float(0.0);
    }
    BankAccount(string name , float account){
        this->name = new string(name);
        this->balance = new float(account);
    }
    BankAccount(const BankAccount &other){
        name = new string(*other.name);
        balance = new float(*other.balance);
    }
    void enterbalnce(float balance){
        this->balance = new float(balance);
    }
    void dispaly(){
        cout << "name : " << *name << " balance : " << *balance << endl;
    }
};
int main(){
    BankAccount acount1;
    BankAccount acount2("kashif",01002.2);
    BankAccount acount3(acount2);
    acount1.dispaly();
    acount2.dispaly();
    acount3.dispaly();
    acount3.enterbalnce(7999.2);
    acount2.dispaly();
    acount3.dispaly();
}