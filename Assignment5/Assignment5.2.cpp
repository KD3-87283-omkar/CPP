#include <iostream>
using namespace std;

class Student
{
    string name;
    string gender;
    const int rollno;
    static int generated; 
    int arr[3];

    public:
    Student():rollno(++generated)
    {
        name="Adi";
        gender="male";
        arr[0]=55;
        arr[1]=84;
        arr[2]=74;
    }
    Student(string name,string gender,int arr[]):rollno(++generated)
    {
        this->name=name;
        this->gender=gender;
        for(int i=0;i<3;i++)
        {
            this->arr[i]=arr[i];
        }
    }
    int getId()
    {
        return this->rollno;
    }

    void accept()
    {
        cout<<"enter name of student: "<<endl;
        cin>>name;
        cout<<"Enter gender of student: "<<endl;
        cin>>gender;
        cout<<"enter three subject marks: "<<endl;
        for(int i=0;i<3;i++)
        {
            cin>>arr[i];
        }
    }
    void display()
    {
        cout<<"Id of student: "<<rollno<<endl;
        cout<<"Name of student: "<<name<<endl;
        cout<<"Gender of student: "<<gender<<endl;
        cout<<"Three subject marks: "<<endl;
        int sum=0;
        for(int i=0;i<3;i++)
        {
            sum+=arr[i];
            cout<<arr[i]<<endl;
        }
        cout<<"percentage is:"<<sum/3<<endl;
    }
};
  int Student::generated=0;
  bool search(Student *arr[5],int id)
  {
    for(int i=0;i<5;i++)
    {
        if(arr[i]->getId()==id)
        {
            return true;
        }
    }
    return false;

  }
  int menu()
  {
    int n;
    printf("for exit press 0\n");
    printf("for Accept Student Details 1\n");
    printf("for Display Details 2\n");
    printf("for Search Student 3\n");
    printf("enter choice\n");
    scanf("%d",&n);
    return n;

  }
int main()
{
Student * arr[5];
for(int i=0;i<5;i++)
{
    arr[i]=new Student();
}
int count=0;
int ch;
while ((ch=menu())!=0)
{
    switch (ch)
    {
    case 1:
        arr[count++]->accept();
    break;
    case 2:
    for(int i=0;i<count;i++)
    {
        arr[i]->display();   
    } 
    break;
    case 3:
        int id;
        cout<<"enter id to search student: ";
        cin>>id;
         cout<<search(arr,id)<<endl;
        break;
    default:
        break;
    }
}
    return 0;
}