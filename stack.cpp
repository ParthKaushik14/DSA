#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
            cout << "stack overflow";
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
            cout << "stack underflow";
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "stack underflow";
            return -1;
        }
    }
    bool isempty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};
int main()
{
    Stack st(5);
    st.push(22);
    st.push(33);
    st.push(41);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;



    // creation of stack
    /*
    stack<int> s;
    // push operation
    s.push(2);
    s.push(4);
    // pop function
    s.pop();
    cout << "Printing top element " << s.top() << endl;
    if (s.empty())
    {
        cout << "stack is empty " << endl;
    }
    else
        cout << "stack is not empty ";
        */

    return 0;
}