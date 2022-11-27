#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    int key;
    Node* next;

    Node(){
        data=0;
        key=0;
        next=NULL;
    }

    Node(int d, int k){
        data=d;
        key=k;
        next=NULL;
    }
};

class CircularLinked{
    public:
    Node* head;

    CircularLinked()
    {
        head=NULL;
    }

    CircularLinked(Node* n)
    {
        head=n;
        head->next=head;
    }

    Node* nodeExists(int k){
        Node* temp=NULL;
        Node* ptr=head;

        if(head==NULL)
        {
            return temp;
        }
        else{
            do{
                if(ptr->key==k)
                {
                    temp=ptr;
                }
                ptr=ptr->next;
            }while(ptr!=head);
            return temp;
        }
    }

    void appendNode(Node* n){
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"Node Exists with Key "<<n->key<<endl;
            return;
        }
        else{
            if(head==NULL)
            {
                head=n;
                head->next=head;
                cout<<"Node appended at Head Node"<<endl;
            }
            else{
                Node* ptr=head;
                while(ptr->next!=head)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                n->next=head;
                cout<<"Node appended Successfully"<<endl;
            }
        }
    }

    void prependNode(Node* n){
        if(nodeExists(n->key)!=NULL)
        {
            cout<<"Node Already Exists with Key "<<n->key<<endl;
            return;
        }
        else{
            if(head==NULL)
            {
                head=n;
                head->next=head;
                cout<<"Node Prepended at head"<<endl;
            }
            else{
                Node* ptr=head;
                while(ptr->next!=head)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                n->next=head;
                head=n;
                cout<<"Node Prepended Successfully"<<endl;
            }
        }
    }

    void insertNodeByKey(int k,Node* n){
        Node* ptr=nodeExists(k);
        if(ptr==NULL)
        {
            cout<<"No Node with key "<<k<<" Exists to insert after"<<endl;
            return;
        }
        else{
            if(nodeExists(n->key)!=NULL)
            {
                cout<<"Node with key "<<n->key<<" Already Exists"<<endl;
                return;
            }
            else
            {
                if(ptr->next==head){
                    ptr->next=n;
                    n->next=head;
                    cout<<"Node Inserted At End."<<endl;
                }
                else{
                    n->next=ptr->next;
                    ptr->next=n;
                    cout<<"Node Inserted in Between."<<endl;
                }
            }
        }
    }

    void deleteNodeByKey(int k)
    {
        Node* ptr=nodeExists(k);
        if(ptr==NULL){
            cout<<"No node with key "<<k<<" Exists."<<endl;
            return;
        }
        else{
            if(ptr==head)
            {
                if(head->next==head)
                {
                    head=NULL;
                    cout<<"Node deleted list became Empty"<<endl;
                }
                else{
                    Node* ptr1=head;
                    while(ptr1->next!=head){
                        ptr1=ptr1->next;
                    }
                    ptr1->next=head->next;
                    head=head->next;
                    cout<<"Deleted Node At head"<<endl;
                }
                
            }
            else{
                Node* temp=NULL;
                Node* prevNode=head;
                Node* currentNode=head->next;
                while(currentNode!=NULL)
                {
                    if(currentNode->key==k)
                    {
                        temp=currentNode;
                        currentNode=NULL;
                    }
                    else{
                        currentNode=currentNode->next;
                        prevNode=prevNode->next;
                    }
                }
                prevNode->next=temp->next;
                delete temp;
                cout<<"Node Deleted By key "<<k<<endl;
            }
        }
    }

    void updateByKey(int k,int d){
        Node* ptr=nodeExists(k);
        if(ptr!=NULL){
            ptr->data=d;
            cout<<"Update Node By Key "<<k<<" with Data "<<d<<endl;
        }
        else{
            cout<<"Node doesn't Exists with Key "<<k<<endl;
        }
    }

    void display()
    {
        if(head==NULL){
            cout<<"Linked List is Empty."<<endl;
        }
        else{
            cout<<"With Head:"<<"("<<head->key<<","<<head->data<<")"<<endl;
            cout<<"Circular Linked List is:"<<endl;
            Node* ptr=head;
            do
            {
                cout<<"("<<ptr->key<<","<<ptr->data<<")"<<"-->";
                ptr=ptr->next;
            } while (ptr!=head);
            cout<<endl;
        }
    }
};

int main()
{
    CircularLinked s;
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
            s.insertNodeByKey(key1,n);
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
    return 0;
}