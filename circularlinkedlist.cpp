#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    // constructor
    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertatNode(node *&tail, int element, int d)
{
    // assuming that the element is present in list
    if (tail == NULL)
    {
        node *newNode = new node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        node *curr = tail;
        while (curr->data != element)
        {
            /* code */
            curr = curr->next;
        }
        // element found -> curr is representing element wala node
        node *temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(node *tail)
{
    node *temp = tail;

    do
    {
        cout << tail->data << " ";
        tail = tail->next;

    } while (tail != temp);
    cout << "\n";
}

void deleteNode(node *&tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        cout << "already empty" << endl;
        return;
    }
    else
    {
        // non empty & assume value is present in list
        node *prev = tail;
        node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        if (tail == NULL)
        {
            cout << " list is empty"
                 << "\n";
                 return;
        }
        // 1 node LL
        if (curr == prev)
        {
            tail = NULL;
        }
        // >= 2 elements LL
        if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    node *tail = NULL;
    insertatNode(tail, 5, 3);
    print(tail);
    insertatNode(tail, 3, 5);
    print(tail);
    insertatNode(tail, 5, 7);
    print(tail);
    insertatNode(tail, 7, 9);
    print(tail);
    insertatNode(tail, 5, 6);
    print(tail);
    deleteNode(tail, 3);
    print(tail);

    return 0;
}