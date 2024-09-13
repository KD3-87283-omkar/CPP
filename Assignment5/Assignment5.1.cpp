#include <iostream>
using namespace std;

class Date
{
    int day;
    int month;
    int year;
    public:
    Date()
    {
        day=10;
        month=5;
        year=2200;
    }
    Date(int d,int m,int y)
    {
        this->day=d;
        month=m;
        year=y;
    }
    void setDay(int d)
    {
       this->day=d;
    }
    void setMonth(int m)
    {
        this->month=m;
    }
    void setYear(int y)
    {
        year=y;
    }
    void accept()
    {
        cout<<"Enter day, month and year"<<endl;
        cin>>day>>month>>year;
    }
    void display()
    {
        cout<<"date is: "<<day<<":"<<month<<":"<<year<<endl;
    }
};
class Person
{
    string name;
    string address;
    Date birthdate;
public:
Person()
{
    name="omkar";
    address="satara";
}
Person(string name,string address,int day,int month,int year)
{
   this->name=name;
   this->address=address;
   this->birthdate.setDay(day);
   this->birthdate.setMonth(month);
   this->birthdate.setYear(year);
}
void accept()
    {
        cout<<"Enter name, address"<<endl;
        cin>>name>>address;
        birthdate.accept();

    }
void display()
{
    cout<<"Person name is :"<<name<<endl;
    cout<<"address is: "<<address<<endl;
    birthdate.display();
}



};

int main()
{

Person p;
p.accept();
p.display();
}