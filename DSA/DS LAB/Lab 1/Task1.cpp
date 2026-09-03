#include "iostream"
using namespace std;

class Book
{
    string author, title;
    int *quantity;

public:
    Book() : author("unknown"), title("unknown") { quantity = new int(0); }
    Book(string author, string title, int quantity) : author(author), title(title) { this->quantity = new int(quantity); }
    Book(const Book &other)
    {
        author = other.author;
        title = other.title;
        quantity = new int(*other.quantity);
    }
    void add_quanttity(int quantity)
    {
        this->quantity = new int(quantity);
    }
    void display()
    {
        cout << " Author : " << author << " Title : " << title << " quantity : " << *quantity << endl;
    }
};
int main()
{
    Book book1;
    Book book2("the hobbit", "jk", 12);
    Book book3(book2);
    book1.display();
    book2.display();
    book3.display();
    book3.add_quanttity(13);
    book1.display();
    book2.display();
    book3.display();
}