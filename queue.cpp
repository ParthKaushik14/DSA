#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    queue<int> q;
    q.push(17);
    cout << q.front();
    q.push(15);
    cout << q.front();

    q.push(13);

    cout << "size of queue is : " << q.size();
    q.pop();
    cout << "size of queue is : " << q.size();
set<int> s;

    return 0;
}