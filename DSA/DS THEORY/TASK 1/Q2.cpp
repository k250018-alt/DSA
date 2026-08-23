#include"iostream"
using namespace std;

class Document{
    string *text;
    public:
    Document(){
        text = new string("unknown");
    }
    Document(string text ){
        this->text = new string(text);
    }
    Document(const Document &other){
        text = new string(*other.text);
    }
    void entertext(string text){
        this->text = new string(text); 
    }
    void dispaly(){
        cout << "Text : " << *text << endl;
    }
    Document& operator =(const Document& other){
        text = new string(*other.text);
    } 
    ~Document(){
        cout << *text << " Destroyed" << endl;
    }
};
int main(){
    Document acount1;
    Document acount2("kashif");
    Document acount3(acount2);
    Document acount4 = acount2;
    acount1.dispaly();
    acount2.dispaly();
    acount3.dispaly();
    acount4.dispaly();
    acount2.entertext("7999.2");
    acount2.dispaly();
    acount3.dispaly();
    acount4.dispaly();
}