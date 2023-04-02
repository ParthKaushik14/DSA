#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for tht node with data " << value << endl;
    }
};
void insertAthead(Node *&head, int d)
{
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAttail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = tail->next;
}
void insertAtposition(Node *&tail, Node *&head, int position, int d)
{ // insert at start
    if (position == 1)
    {
        insertAthead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    // insert at middle
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // insertatlast
    if (temp->next == NULL)
    {
        insertAttail(tail, d);
        return;
    }

    // creating node for d
    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // any node deleting except 1st node
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;
    // head pointing node 1;
    Node *head = node1;
    // tail pointing node1 ;
    Node *tail = node1;
    insertAttail(tail, 12);
    insertAttail(tail, 15);
    insertAtposition(tail, head, 2, 4);
    insertAtposition(tail, head, 1, 45);

    print(head);
    cout << "\n";
    cout << head->data << "\n";
    cout << tail->data << "\n";
    deleteNode(2, head);
    print(head);

    return 0;
}