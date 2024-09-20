#include<iostream>
using namespace std;

class Employee
{
    int id;
    double salary;
    public:
    Employee()
    {
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
class Manager:virtual public Employee
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
        acceptManager();
        
    }
    void display()
    {
        Employee::display();
        displayManager();
        
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
    void accept()
    {
        Employee::accept();
        acceptSalesman();
    }
    void display()
    {
        Employee::display();
        displaySalesman();
    }
    protected:
    void acceptSalesman()
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
        this->acceptSalesman();
    }
    void display()
    {
        Employee::display();
        this->displayManager();
        this->displaySalesman();
    }
};
int menu()
{
    cout<<"For Exit press 0\n";
    cout<<"For Accept Manger press 1\n";
    cout<<"For Accept Salesman press 2\n";
    cout<<"For Accept SalesManager press 3\n";
    cout<<"For display count of employees with respect to designation press 4\n";
    cout<<"Display all Managers press 5\n";
    cout<<"Display All Salesman press 6\n";
    cout<<"Dispaly all SalesManager press 7\n";
    cout<<"Enter your choice\n";
     int n;
     cin>>n;
    return n;
}
int main()
{
    int index=0;
    Employee *e[5];
    
    int ch;
    while((ch=menu())!=0)
    {
        
        switch (ch)
        {
        case 1:
            e[index]=new Manager;
            e[index]->accept();
            index++;
            break;
        case 2:
          e[index]=new Salesman;
          e[index]->accept();
          index++;
          break;
        case 3:
          e[index]=new SalesManager;
          e[index]->accept();
          index++;
          break;
        case 4:
        {
        int m=0;int s=0;int sm=0;
        for(int i=0;i<index;i++)
        {
            if(typeid(*e[i])==typeid(Manager))
            {
                m++;
            }
            if(typeid(*e[i])==typeid(Salesman))
            {
                s++;
            }
            if(typeid(*e[i])==typeid(SalesManager))
            {
                sm++;
            }
        }
        cout<<"Manager count is :"<<m<<endl;
        cout<<"saleman count is :"<<s<<endl;
        cout<<"SalesManager is :"<<sm<<endl;
        break;
        }
        case 5:
        for(int i=0;i<index;i++)
        {
            if(typeid(*e[i])==typeid(Manager))
            {
                e[i]->display();
            }
            cout<<"\n";
        }
        break;
        case 6:
        for(int i=0;i<index;i++)
        {
            if(typeid(*e[i])==typeid(Salesman))
            {
                e[i]->display();
            }
            cout<<"\n";
        }
        break;
        case 7:
        for(int i=0;i<index;i++)
        {
            if(typeid(*e[i])==typeid(SalesManager))
            {
                e[i]->display();
            }
            cout<<"\n";
        }
        break;
        default:
        cout<<"wrong input\n";
            break;
        }
    }

    return 0;
}