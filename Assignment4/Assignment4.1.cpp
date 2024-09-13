#include <iostream>
#include<string.h>
using namespace std;

class Time
{
    int hr;
    int min;
    int sec;
public:
    Time()
    {
    this->hr=10;
    this->min=5;
    this->sec=10;
    }
    Time(int h,int m,int s)
    {
        this->hr=h;
        this->min=m;
        this->sec=s;
    }
    
    int getHour()
    {
        return this->hr;
    }
    int getMin()
    {
        return this->min;
    }
    int getSec()
    {
        return this->sec;
    }
    void setHour(int hour)
    {
        this->hr=hour;
    }
    void setMinute(int minute)
    {
          this->min=minute;
    }
    void setSecond(int second)
    {
        this->sec=second;
    }
    void accept()
    {
        cout << "Enter time (hours, minutes, seconds): ";
        cin >> hr >> min >> sec;
    }
      void display()
    {
        cout << "Time is: " << this->hr << "-" << this->min << "-" << this->sec << endl;
    }
};

int main()
{
      Time **ptr=new Time*[5];




      for(int i=0; i<5; i++){
        ptr[i] = new Time();
      }
     //ptr[1]->accept();
      ptr[1]->display();
       // ptr[0]->setHour(10);
    // ptr[0]->setMinute(20);
    // ptr[0]->setSecond(30);
    //cout<<ptr[0]->getHour()<<":"<<ptr[0]->getMin()<<":"<<ptr[0]->getSec();
    //  for(int i=0;i<5;i++)
    //  {
    //     ptr[i]->accept();
    //     ptr[i]->display();
    //  }

      for(int i=0;i<5;i++)
      {
        delete ptr[i];
        ptr[i]=nullptr;
      }
     delete []ptr;
     ptr=NULL;


    return 0;
}