#include <iostream>
using namespace std;
class Employee
{
    int id;
    double salary;

public:
    Employee()
    {
        cout<<"Inside Employee"<<endl;
    }
    Employee(int id, double sal)
    {
        this->id = id;
        this->salary = sal;
    }
    void setId(int id)
    {
        this->id = id;
    }
    int getId()
    {
        return id;
    }
    void setSalary(int sal)
    {
        this->salary = sal;
    }
    double getSalary()
    {
        return salary;
    }
    virtual void accept()
    {
        cout << "Enter id" << endl;
        cin >> id;
        cout << "Enter salary" << endl;
        cin >> salary;
    }
    virtual void display()
    {
        cout << "Employee id is: " << id << endl;
        cout << "Employee salary is: " << salary << endl;
    }
};
class Manager : virtual public Employee
{
    
    double bonus;
    protected:
    void acceptManager()
    {
        cout<<"Enter bonus"<<endl;
        cin>>bonus;
    }
    void displayManager()
    {
        cout<<"Bonus is  :"<<bonus<<endl;
    }
    public:
    Manager()
    {
        bonus=55;
        cout<<"inside MAnager"<<endl;

    }
    Manager(int id,double sal,double bonus):Employee(id,sal)
    {
        this->bonus = bonus;
    }
    void setBonus(double b)
    {
        this->bonus=b;
    }
    double getBonus()
    {
         return bonus;
    }
    void accept()
    {
        Employee::accept();
        
    }
    void display()
    {
        Employee::display();
        
    }
};
class Salesman:virtual public Employee
{
    double commission;
    public:
    Salesman()
    {
        commission=400;
    }
    Salesman(int id,double sal,double commision):Employee(id,sal)
    {
        this->commission=commision;
    }
    void setCommision(double commision)
    {
         this->commission=commision;
    }
    double getCommision()
    {
        return commission;
    }
    void acceptSaleman()
    {
        cout<<"Enter Commision "<<endl;
        cin>>commission;
    }
    void displaySalesman()
    {
        cout<<"Commision is: "<<commission<<endl;
    }
};
class SalesManager:public Salesman,public Manager
{
    public:
    SalesManager()
    {
          cout<<"inside salesmanager constructor"<<endl;
    }
    SalesManager(int id,double sal,double bonus,double commision):Employee(id,sal)
    {
        this->setCommision(commision);//Salesman:"setCommision(comm)"
        this->setBonus(bonus);
 
    }
    void accept()
    {
        Employee::accept();
        //Manager::accept();
        this->acceptManager();
        this->acceptSaleman();
    }
    void display()
    {
        Employee::display();
        this->displayManager();
        this->displaySalesman();
    }
};
int main()
{
     Employee *e=new SalesManager;
     e->accept();
     e->display();
    

}
