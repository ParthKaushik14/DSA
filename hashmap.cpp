#include <bits/stdc++.h>
using namespace std;
int main()
{
    // creation
    unordered_map<string, int> m;

    // insertion
    pair<string, int> p = make_pair("babbar", 3);
    m.insert(p);

    pair<string, int> p2("love", 2);
    m.insert(p2);

    m["mera"] = 1;

    // search
    cout << m["mera"] << "\n";
    cout << m.at("babbar") << endl;

    // size
    cout << m.size() << endl;
    // to check whether present or not

    cout << m.count("love") << endl;

    cout << m.erase("love") << "\n";
    cout << m.size() << endl;

    // iterator

    unordered_map<string, int>::iterator it = m.begin();

    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}