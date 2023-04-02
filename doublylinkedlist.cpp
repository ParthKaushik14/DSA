#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;
    // constructor
    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    ~node()
    {
        int val = this -> data; 
        if(next != NULL)
        {
            delete next;
            next =NULL;

        }
            cout<<"memory free for node with data "<<val<<endl;
    }
};
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(node *&head)
{
    node *temp = head;
    int l = 0;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
void insertatHead(node *&tail , node *&head, int d)
{
    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
        tail = temp;

    }
    else
    {
        node *temp = new node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertatTail(node *&tail,node *&head, int d)
{
    if (tail == NULL)
    {
        node *temp = new node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        node *temp = new node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertatPosition(node *&tail, node *&head, int position, int d)
{
    // insert at start
    if (position == 1)
    {
        insertatHead(tail , head, d);
        return;
    }
    node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // insert at last
    if (temp->next == NULL)
    {
        insertatTail(tail,head , d);
        return;
    }

    // creating node for d
    node *nodetoInsert = new node(d);
    nodetoInsert->next = temp->next;
    temp->next->prev = nodetoInsert;
    temp->next = nodetoInsert;
    nodetoInsert->prev = temp;
}
void deleteNode(int position, node *&head)
{
    // deleting first or start node
    if (position == 1)
    {
        node *temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        node *curr = head;
        node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        curr -> prev =NULL;
        prev -> next = curr ->next;
        curr -> next = NULL;

        
        delete curr; 

    }
}

int main()
{

    node *node1 = new node(10);
    //node *head = node1;
    //node *tail = node1;
    node *head = NULL;
    node *tail = NULL;
    print(head);
    cout << getLength(head) << endl;
    insertatHead(tail , head, 12);
    print(head);
    insertatTail(tail, head ,  25);
    print(head);
    insertatPosition(tail, head, 2, 100);
    print(head);
    insertatPosition(tail, head, 1, 105);
    print(head);
    insertatPosition(tail, head, 5, 105);
    print(head);

deleteNode(3, head);
print(head);
    return 0;
}