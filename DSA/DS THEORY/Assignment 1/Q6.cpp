#include "iostream"
#include "Singly_ll.h"  
using namespace std;

struct Song{
    string title;
    string genere;
    int duration;
    bool explicit_content;
    ~Song(){
        if(explicit_content){
            cout <<"this is explicit content to destroy making it not explicit to delete ";
            explicit_content = false;
        }
    }
};
ostream& operator<<(ostream&os ,const Song&r){
       os << r.title << ":" <<  r.genere <<" : " << r.duration << " : " << r.explicit_content;
       return os;
    }
istream& operator>>(istream&is ,Song &r){
    is >>r.title >> r.genere >> r.duration >> r.explicit_content;
    return is;
}
bool checkconsecutive(Singly_LL<Song> list){
    for(int i = 0 ; i < list.get_count()-2 ; i++){
        if(list.search_Node(i).duration + list.search_Node(i+1).duration +list.search_Node(i+2).duration > 600){
            return false;
        }
    }
    return true;
}
Singly_LL<Song> inputcheck(Singly_LL<Song> list){
    Song s;
    cout << "enter the Song details ";
    cin >> s;
    if(list.get_count() >= 2){
        if(list.search_Node(0).genere != s.genere ){
            list.inserthead(s);
            if(checkconsecutive(list)){
                return list;
            }
            list.delete_node(0);
        }
        for(int i = 0 ; i < list.get_count()-1 ; i++){
            if(list.search_Node(i).genere != s.genere && list.search_Node(i+1).genere != s.genere ){
                if(list.search_Node(i).duration + list.search_Node(i+1).duration + s.duration <= 600){
                    list.insertinbetween(s,i);
                    if(checkconsecutive(list)){
                        return list;
                    }
                    list.delete_node(i+1);
                }
            }
    }
    if(list.search_Node(list.get_count()-1).genere != s.genere){
        if( list.search_Node(list.get_count()-1).duration + list.search_Node(list.get_count()-2).duration + s.duration <= 600){
            list.insert(s);
            return list;
    }
    }
    cout << "No valid position to enter the song :" << endl;
    return list;
}
else{
    if(list.get_count() == 0 ){
        list.insert(s);
        return list;
    }
    else if(list.get_count() == 1){
        if(list.search_Node(0).genere != s.genere){
            list.insert(s);
            return list;
        }
        cout << "No valid position to enter the song :" << endl;
        return list;
    }
}
return list;
}
int main(){
    Singly_LL<Song> list_of_songs;
    char choice;
    do{
        list_of_songs = inputcheck(list_of_songs);
        cout << "Enter x to exit "<<endl;
        cin>>choice;
    }while(choice != 'x');
    list_of_songs.display();
}