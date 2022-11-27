#include<bits/stdc++.h>
using namespace std;

class Queue{
    private:
    int rear,front;
    int * arr;
    public:
    Queue(){
        arr=new int[5];
        rear=-1;
        front=-1;
        for(int i=0;i<5;i++)
        {
            arr[i]=0;
        }
    }
    bool isEmpty()
    {
        return (front==-1 && rear==-1);
    }
    bool isFull()
    {
        return rear==4;
    }
    void Enqueue(int val)
    {
        if(isFull())
        {
            cout<<"Queue is Already Full"<<endl;
            return;
        }
        else if(isEmpty())
        {
            front=0;
            rear=0;
        }
        else
        {
            rear++;
        }
        arr[rear]=val;
    }
    int Dequeue()
    {
        int x=0;
        if(isEmpty())
        {
            cout<<"Queue is Already Empty"<<endl;
            return 0;
        }
        else if(front==rear)
        {
            x=arr[front];
            arr[front]=0;
            front=-1;
            rear=-1;
            return x;
        }
        else{
            x=arr[front];
            arr[front]=0;
            front++;
            return x;
        }
    }
    int count()
    {
        return ((rear+1)-front);
    }
    void display()
    {
        cout<<"Elements in queue are:"<<endl;
        for(int i=0;i<5;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Queue q1;
    int option,val,index;
     do
    {
        cout<<"enter number for operation:"<<endl;
        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"Enter Value to Enqueue"<<endl;
                cin>>val;
                q1.Enqueue(val);
                break;
            case 2:
                cout<<"Dequeued element is "<<q1.Dequeue()<<endl;
                break;
            case 3:
                if(q1.isFull())
                {
                    cout<<"Queue is Full"<<endl;
                }
                else
                {
                    cout<<"Queue is not Full"<<endl;
                }
                break;
            case 4:
                if(q1.isEmpty())
                {
                    cout<<"Queue is Empty"<<endl;
                }
                else
                {
                    cout<<"Queue is not Empty"<<endl;
                }
                break;
            case 5:
                q1.display();
                break;
            case 6:
                cout<<"Total number of elements are:"<<q1.count()<<endl;
                break;
            default:
                cout<<"Enter proper Option"<<endl;
        }
    } while (option>=0 && option<=6);
    return 0;
}