#include <bits/stdc++.h>
using namespace std;
// 1. algos 2. functions 3. iterators 4. containers
int main()
{ // pair comes under utility library
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << "\n";
    pair<int, pair<int, int>> p = {1, {2, 3}};

    pair<int, int> arr[] = {{0, 1}, {1, 2}, {2, 3}};

    vector<pair<int, int>> vec;
    // emplace back faster than pushback
    vec.push_back({1, 2});
    vec.emplace_back(3, 4); // automatically gets this

    // v(size , content)
    vector<int> v(5, 20);
    // v(size) with garbage value filled
    vector<int> v(5);
    vector<int> v1(v); // copies

    // iterators
    //  points memory address

    vector<int>::iterator it = v.begin();
    // v.begin pointing towards first memory
    it++;
    cout << *(it) << " ";
    vector<int>::iterator it = v.end();
    // emd pooints after the last element of vector for printing last element we first have to it--
    //  v.rend() points before0th element
    // v.rbegin points last element they both works in reverse way means even if we it++ they will move backwards

    // for printing entire vector
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        /* code */
        cout << *(it) << "\n";
    }

    return 0;
}