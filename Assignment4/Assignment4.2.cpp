#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    int top ;
    int *arr;

public:
    Stack(int size)
    {
        arr = new int[size];
        top = -1;
    }
    bool isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        if(top-1==size)
        {
            return true;
        }
        return false;
    }
    void push(int data)
    {
        if(!isFull())
        {
        top++;
        arr[top] = data;
        }
    }
    void pop()
    {
        if(!isEmpty())
        {
        cout << arr[top]<<endl;
        top--;
        }
    }
    int peek()
    {
        return arr[top];
    }
    void print()
    {
       while(top!=-1)
       {
           cout<<peek()<<endl;
           top--;
       }
    }
};
int main()
{
    Stack *s=new Stack(5);
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(5);
    cout<<s->peek()<<endl<<endl;
    s->print();
    delete s;
    s=nullptr;
    return 0;
}