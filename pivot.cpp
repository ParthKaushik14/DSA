#include <iostream>
using namespace std;
/*int getPivot(int arr[], int n )
{
    int s = 0;
    int e = n-1;
    int mid =  s + (e-s)/2;
    while (s<e)
    {
        if (arr[mid] >= arr[0])
        {
            s =mid + 1;
        }
        else{
            e = mid ;
        }
        mid = s + (e-s)/2;
    }
    return e;
}
int main(){
int arr[5] = {8,10,17,1,3};
cout<<"Pivot is "<<getPivot(arr,5)<<endl;
return 0;} */

class CircularQueue
{
    int *arr;
    int front;
    int rear;

    int size;

public:
    // Initialize your data structure.
    CircularQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;

        // Write your code here.
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
        {
            {
                // cout<<"queue is full";
                return false;
            }
        }
            else if (front == -1)
            {
                front = rear = 0;
            }
            else if (rear == size - 1 && front != 0)
            {
                rear = 0;
            }
            else
            {
                rear++;
            }
            arr[rear] = value;
            return true;
        }

        // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
        int dequeue()
        {
            if (front == -1)
            {
                // cout<<"queue is empty"<<endl;
                return false;
            }
            if (front == rear)
            {
                front = rear = -1;
            }
            else if (front == size - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
            return true;
        }
    };