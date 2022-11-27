#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int key;
    int data;
    Node* next;
    Node()
    {
        key=0;
        data=0;
        next=NULL;
    }
    Node(int k,int d)
    {
        key=k;
        data=d;
        next=NULL;
    }
};

class SinglyLinked
{
    public:
    Node* head=NULL;
    SinglyLinked()
    {
        head=NULL;
    }
    SinglyLinked(Node* n)
    {
        head=n;
    }
    Node* nodeExists(int k)
    {
       Node* temp=NULL;
       Node* ptr=head;
       while(ptr!=NULL)
       {
        if(ptr->key==k)
        {
            temp=ptr;
        }
        ptr=ptr->next;
       }
       return temp;
    }

    void appendNode(Node* n){
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"Node with Key:"<<n->key<<" Already exists."<<endl;
            return;
        }
        else
        {
            if(head==NULL)
            {
                head=n;
                cout<<"Node Appended."<<endl;
            }
            else
            {
                Node* ptr=head;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                cout<<"Node Appended."<<endl;
            }
        }
    }

    void prepend(Node *n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"Node with Key:"<<n->key<<" Already exists."<<endl;
            return;
        }
        else
        {
            if(head==NULL)
            {
                head=n;
                cout<<"Node Prepended."<<endl;
            }
            else
            {
                n->next=head;
                head=n;
                cout<<"Node Prepended."<<endl;
            }
        }
    }

    void insertNodeAfterKey(int k,Node* n)
    {
        Node* ptr=nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"Node doesn't Exists with key:"<<k;
        }
        else
        {
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"Node with Key:"<<n->key<<" Already Exists."<<endl;
            }
            else
            {
                n->next=ptr->next;
                ptr->next=n;
                cout<<"Node Inserted with key:"<<n->key<<endl;
            }
        }
    }
    void deleteByKey(int k)
    {
        if(head==NULL)
        {
            cout<<"Linked List is already empty"<<endl;
        }
        else
        {
            Node* temp=NULL;
            Node* previous=head;
            Node* current=head->next;
            if(head->key==k)
            {
                head=head->next;
                cout<<"Node deleted with key:"<<k<<endl;
            }
            else
            {
                
                while(current!=NULL)
                {
                    if(current->key==k)
                    {
                        temp=current;
                        current=NULL;
                    }
                    else
                    {
                        current=current->next;
                        previous=previous->next;
                    }
                }
                
            }
            if(temp!=NULL)
            {
                previous->next=temp->next;
                cout<<"Node deleted with key:"<<k<<endl;
            }
            else
            {
                cout<<"Node doesn't Exists with Key:"<<k<<endl; 
            }
        }
    }
    void updateByKey(int k,int d)
    {
        Node* ptr=nodeExists(k);
        if(ptr!=NULL)
        {
            ptr->data=d;
            cout<<"Node with key:"<<k<<" Updated to data:"<<d<<endl;
        }
        else
        {
            cout<<"Node doesn't Exists with Key:"<<k<<endl;
        }
    }

    void display()
    {
        if(head==NULL)
        {
            cout<<"No Nodes in Singly Linked list"<<endl;
        }
        else
        {
            cout<<endl<<"Singly Linked List is:"<<endl;
            Node* ptr=head;
            while(ptr!=NULL)
            {
                cout<<"("<<ptr->key<<","<<ptr->data<<") -->";
                ptr=ptr->next;
            }
            cout<<endl;
        }
    }
};
int main()
{
    SinglyLinked s;
    int option,key1,data1;
    do
    {
        cout<<"Enter option for operation:\n 1.Append \n 2.Prepend \n 3.Insert Node \n 4.Delete Node \n 5.Update Node \n 6.Display Linked List \n [Enter 0 to Exit]"<<endl;
        cin>>option;
        Node* n=new Node();
        switch(option)
        {
            case 1:
            cout<<"To Append Node Enter Key & Data:"<<endl;
            cin>>key1;
            cin>>data1;
            n->key=key1;
            n->data=data1;
            s.appendNode(n);
            break;

            case 2:
            cout<<"To Prepend Node Enter Key & Data:"<<endl;
            cin>>key1;
            cin>>data1;
            n->key=key1;
            n->data=data1;
            s.prepend(n);
            break;

            case 3:
            cout<<"To Insert Node Enter Key & Data:"<<endl;
            cin>>key1;
            cin>>data1;
            n->key=key1;
            n->data=data1;
            cout<<"Enter key after which node is supposed to insert:"<<endl;
            cin>>key1;
            s.insertNodeAfterKey(key1,n);
            break;

            case 4:
            cout<<"Enter key of Node supposed to be deleted"<<endl;
            cin>>key1;
            s.deleteByKey(key1);
            break;

            case 5:
            cout<<"To Update Node Enter Key & Data:"<<endl;
            cin>>key1;
            cin>>data1;
            s.updateByKey(key1,data1);
            break;

            case 6:
            s.display();
            break;

            default:
            cout<<"Enter Proper option!!"<<endl;
            break;
        }
    } while (option!=0);
    
}