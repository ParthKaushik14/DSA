#include <iostream>
using namespace std;
void reverse(string &str, int i, int j)
{
    if (i > j)
    {
        return;
    }
    swap(str[i], str[j]);
    i++;
    j--;

    reverse(str, i, j);
}

bool checkpalindrome(string str, int i, int j)
{
    if(i>j)
    return true;

    if(str[i] != str[j])
    return false;
    else {
        return checkpalindrome(str, i+1 , j-1);
    }
}
int main()
{
    string name = "boob";
    // reverse(name, 0, name.length() - 1);
    // cout << name << endl;
    bool ispalindrome = checkpalindrome(name, 0, name.length() - 1);

    if(ispalindrome)
    cout<<"YES";
    else
    cout<<"NO";
    return 0;
}