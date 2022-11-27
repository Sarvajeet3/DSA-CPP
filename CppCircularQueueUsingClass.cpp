#include<bits/stdc++.h>
using namespace std;

class CircularQueue{
    private:
    int* arr;
    int front;
    int rear;
    public:
    CircularQueue(){
        arr=new int[5];
        front=-1;
        rear=-1;
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
        return ((rear+1)%5)==front;
    }
    void Enqueue(int val)
    {
        if(isFull())
        {
            cout<<"Queue IS already Full";
            return;
        }
        else if(isEmpty())
        {
            front=0;
            rear=0;
        }
        else
        {
            rear=(rear+1)%5;
        }
        arr[rear]=val;
    }
    int Dequeue()
    {
        int x;
        if(isEmpty())
        {
            cout<<"Queue IS already Empty"<<endl;
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
            front=(front+1)%5;
            return x;
        }
    }
    void display()
    {
        cout<<"Circular Queue is:"<<endl;
        for(int i=0;i<5;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    CircularQueue q1;
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
            default:
                cout<<"Enter proper Option"<<endl;
        }
    } while (option>=0 && option<=5);
    return 0;
}