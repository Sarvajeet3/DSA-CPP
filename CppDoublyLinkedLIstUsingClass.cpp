#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    int key;
    Node * prev;
    Node * next;
    Node()
    {
        data=0;
        key=0;
        prev=NULL;
        next=NULL;    
    }
    Node(int d,int k)
    {
        data=d;
        key=k;
        prev=NULL;
        next=NULL;
    }
};

class DoublyLinked
{
    public:
    Node* head;
    DoublyLinked()
    {
        head=NULL;
    }
    DoublyLinked(Node* n)
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
                break;
            }
            ptr=ptr->next;
        }
        return temp;
    }

    void appendNode(Node* n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"Node exists with key:"<<n->key<<endl;      
        }
        else
        {
            if(head==NULL)
            {
                head=n;
                cout<<"Node Appended at Head Node"<<endl;
            }
            else
            {
                Node* ptr=head;
                while(ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                n->prev=ptr;
                cout<<"Node Appended At the end"<<endl;
            }
        }
    }

    void prependNode(Node* n)
    {
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"Node exists with key:"<<n->key<<endl;
        }
        else
        {
            if(head==NULL)
            {
                head=n;
                cout<<"Node prepended at Head Node"<<endl;
            }
            else
            {
                head->prev=n;
                n->next=head;
                head=n;
                cout<<"Node prepended successfully"<<endl;
            }
        }
    }

    void insertNodeAfterKey(int k,Node* n)
    {
        Node* ptr=nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"NO Node with key "<<k<<" Exists to insert after."<<endl;
        }
        else
        {
            Node* nextNode=ptr->next;
            if(nextNode==NULL)
            {
                ptr->next=n;
                n->prev=ptr;
                cout<<"Node inserted at the end"<<endl;
            }
            else
            {
                nextNode->prev=n;
                n->next=nextNode;
                ptr->next=n;
                n->prev=ptr;
                cout<<"Node inserted in between"<<endl;
            }
        }
    }

    void deleteNodeByKey(int k)
    {
        Node* ptr=nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"No Node with key "<<k<<" Exists To delete."<<endl;
        }
        else
        {
            if(head->key==k)
            {
                head=head->next;
                head->prev=NULL;
                delete ptr;
                cout<<"Node at head deleted"<<endl;
            }
            else
            {
                Node* prevNode=ptr->prev;
                Node* nextNode=ptr->next;
                if(nextNode==NULL)
                {
                    prevNode->next=NULL;
                    delete ptr;
                    cout<<"Node at end deleted"<<endl;
                }
                else
                {
                    prevNode->next=nextNode;
                    nextNode->prev=prevNode;
                    delete ptr;
                    cout<<"Node deleted in between"<<endl;
                }
            }
        }
    }

    void updateNodeByKey(int k,int d)
    {
        Node* ptr=nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"No Node with key "<<k<<" Exists."<<endl;
        }
        else
        {
            ptr->data=d;
            cout<<"Node with key "<<k<<" updated to data "<<d<<endl;
        }
    }

    void display()
    {
        if(head==NULL)
        {
            cout<<"Linked list is Empty"<<endl;
        }
        else
        {
            Node* ptr=head;
            while(ptr!=NULL)
            {
                cout<<"("<<ptr->key<<","<<ptr->data<<") <--> ";
                ptr=ptr->next;
            }
            cout<<endl;
        }
    }
};

int main()
{
    DoublyLinked s;
     int option,key1,data1;
    do
    {
        cout<<"Enter option for operation:\n 1.Append \n 2.Prepend \n 3.Insert Node \n 4.Delete Node \n 5.Update Node \n 6.Display Linked List \n [Enter 0 to Exit]"<<endl;
        cin>>option;
        Node* n=new Node();
        switch(option)
        {
            case 0:
            break;
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
            s.prependNode(n);
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
            s.deleteNodeByKey(key1);
            break;

            case 5:
            cout<<"To Update Node Enter Key & Data:"<<endl;
            cin>>key1;
            cin>>data1;
            s.updateNodeByKey(key1,data1);
            break;

            case 6:
            s.display();
            break;

            default:
            cout<<"Enter Proper option!!"<<endl;
            break;
        }
    } while (option!=0);
    return 0;
}