#include <iostream>
using namespace std;
class Product
{
   int id;
    string title;
    int price;
public:
    Product() 
    {

    }
    Product(int id,string title,int price)
    {
        this->id=id;
        this->title=title;
        this->price=price;
    }
    int getPrice()
    {
        return price;
    }
   virtual void accept()
    {
        cout<<"Enter Product id\n";
        cin>>id;
        cout<<"Enter title\n";
        cin>>title;
        cout<<"Enter Price\n";
        cin>>price;
    }
    virtual void display()
    {
        cout<<"Product id is: "<<id<<endl;
        cout<<"Title is: "<<title<<endl;
        cout<<"Price is: "<<price<<endl;
    }
}; 
class Book :public Product
{
string author;
public:
    Book()
    {
    }
    Book(string author)
    {
        this->author=author;
    }
    void accept()
    {
        Product::accept();
        cout<<"Enter Author name"<<endl;
        cin>>author;
    }
    void display()
    {
        Product::display();
        cout<<"Author name is"<<author<<endl;
    }
};
class Tape:public Product
{

    string artist;
    public:
    Tape()
    {

    }
    Tape(string artist)
    {
        this->artist=artist;
    }
    void accept()
    {
        Product::accept();
        cout<<"Enter Artist name"<<endl;
        cin>>artist;
    }
    void display()
    {
        Product::display();
        cout<<"Artist name is"<<artist<<endl;
    }
};
int menu()
{
    cout<<"************************************\n";
    cout<<"For Exit press 0\n";
    cout<<"For purchase Book press1\n";
    cout<<"For purchase Tape press 2\n";
    cout<<"Calaculate Final bill press 3\n";
    cout<<"For Dispaly Books press 3\n";
    cout<<"For display Tape pres 4\n";
    int n;
    cout<<"Enter your choice "<<endl;
    cout<<"******************************************\n";
    cin>>n;
    return n;
}
int main()
{
Product *arr[3];
int ch;
int index=0;
while((ch=menu())!=0)
{
    switch(ch)
    {
        case 1:
        {
        arr[index]=new Book;
        arr[index]->accept();
        index++;
        break;
        }
        case 2:
        {
        arr[index]=new Tape;
        arr[index]->accept();
        index++;
        break;
        }
        case 3:
        {
            double bill=0.0;
           for(int i=0;i<index;i++)
           {
            if(typeid(*arr[i])==typeid(Book))
            {
            bill=bill+arr[i]->getPrice()-(arr[i]->getPrice()*0.05);
            }
            if(typeid(*arr[i])==typeid(Tape))
            {
                bill=bill+arr[i]->getPrice()-(arr[i]->getPrice()*0.10);
            }
           }
           cout<<"*************************************\n";
           cout<<"Total bill is: "<<bill<<endl;
           cout<<"*************************************\n";
           break;
        }
        case 4:
        {
            for(int i=0;i<index;i++)
            {
                if(typeid(*arr[i])==typeid(Book))
            {
                arr[i]->display();
            }
            }
            break;
        }
        case 5:
         for(int i=0;i<index;i++)
            {
                if(typeid(*arr[i])==typeid(Tape))
            {
                arr[i]->display();
            }
            }
            break;
    }
    }
}
