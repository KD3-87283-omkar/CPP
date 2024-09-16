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
        cout<<"day, month and year"<<endl;
        cin>>day>>month>>year;
    }
    void display()
    {
        cout<<"date is: "<<day<<":"<<month<<":"<<year<<endl;
    }
};
class Person
{
    public:
    string name;
    string address;
    Date dob;
    //Date doj;

Person()
{
    name="omkar";
    address="satara";
    //dob=nullptr;
    
}
Person(string name,string address,int day,int month,int year):dob(day,month,year)
{
   this->name=name;
   this->address=address;
  // this->dob=nullptr;
}
void accept()
    {
        cout<<"Enter name, address"<<endl;
        cin>>name>>address;
        cout<<"enter Birthdate:";
        dob.accept();

    }
void display()
{
    cout<<"Person name is :"<<name<<endl;
    cout<<"address is: "<<address<<endl;
    cout<<"Date of Birth is :";
    dob.display();
    // if(dob!=NULL)
    // {
    //     dob->display();
    // }
}

// void acceptDateOfBirth()
// {
//     dob=new Date();
//     cout<<"Enter Date Of Birth"<<endl;
//     dob->accept();
// }

// ~Person()
// {
//     if(dob!=NULL)
//     {
//         delete dob;
//         dob=NULL;
//     }
// }
};
class Employee:public Person
{
    const int empid;
    double sal;
    string dept;
    static int count;
    Date doj;
    public :
    Employee():empid(++count)
    {
        
        sal=10000;
        dept="sales";
    }
    Employee(double sal,string dept,int day,int month,int year):doj(day,month,year),empid(++count)
    {
        this->sal=sal;
        this->dept=dept;
    }
    void accept()
    {
        cout<<"Enter salary: "<<endl;
        cin>>sal;
        cout<<"Enter department: "<<endl;
        cin>>dept;
        cout<<"Enter Joining date :";
        doj.accept();
     
    }
    void display()
    {
        cout<<"salary is: "<<sal<<endl;
        cout<<"department is: "<<dept<<endl;
        cout<<"Date Of joining is :";
        doj.display();
    }
};
int Employee::count=0;
int main()
{
    Person *p=new Employee();
    p->accept();
    Employee *ptr=(Employee*)p;
    ptr->accept();
    p->display();
    ptr->display();
}
