#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
    int* arr;
    int top;
    public:
    Stack(){
        arr= new int[5];
        top = -1;
        for(int i=0;i<5;i++)
        {
            arr[i]=0;
        }
    }
    bool isEmpty()
    {
        return top==-1;
    }
    bool isFull()
    {
        return top==4;
    }
    void push(int val)
    {
        if(isFull())
        {
            cout<<"Stack Overflow.";
        }
        else{
            top++;
            arr[top]=val;
        }
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack UnderFlow";
            return 0;
        }
        else{
            int popval=arr[top];
            arr[top]=0;
            top--;
            return popval;
        }
    }
    int peek(int ind)
    {
        if(isEmpty()){
            cout<<"Stack UnderFlow";
            return 0;
        }
        else{
            return arr[ind];
        }
    }
    int count(){
        return top+1;
    }
    void change(int ind, int val)
    {
        arr[ind]=val;
    }
    void display()
    {
        for(int i=top;i>=0;i--)
        {
            cout<<arr[i]<<endl;
        }
    }
};

int main()
{
    Stack s1;
    int option,val,index;
    do
    {
        cout<<"enter number for operation:"<<endl;
        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"Enter Value to push"<<endl;
                cin>>val;
                s1.push(val);
                break;
            case 2:
                cout<<"POPed element is "<<s1.pop()<<endl;
                break;
            case 3:
                cout<<"Is stack Full : "<<s1.isFull()<<endl;
                break;
            case 4:
                cout<<"Is stack Empty : "<<s1.isEmpty()<<endl;
                break;
            case 5:
                cout<<"Display Stack: "<<endl;
                s1.display();
                break;
            case 6:
                cout<<"Enter value to change:";
                cin>>val;
                cout<<"Enter index to change value:";
                cin>>index;
                s1.change(index,val);
                break;
            case 7:
                cout<<"Total number of elements are:"<<s1.count();
                break;
            default:
                cout<<"Enter propare Option";
        }
    } while (option>=0 && option<=7);
    
    return 0;
}