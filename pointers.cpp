#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        if (y < x)
        {
            sort(s.begin(), s.end());
            reverse(s.begin(), s.end());

            for (int i = 0; i < n - 1; i++)
            {
                if (s[i] == '1' && s[i + 1] == '0')
                {
                    cout << y << "\n";
                    break;
                }
            }
        }
        else if (x < y)
        {
            sort(s.begin(), s.end());
            for (int i = 0; i < n - 1; i++)
            {
                if (s[i] == '0' && s[i + 1] == '1')
                {
                    cout << x << "\n";
                    break;
                }
            }
        }
        else
            cout << "0"
                 << "\n";
    }
    return 0;
}
