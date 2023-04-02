#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 10;
const int m = 1e9 + 7;
#define MOD 1000000007

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputs.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        map<int, int> m;

        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
            m[x]++;
        }

        long long ans = 0;
        long long last = 1;

        for (int i = 1; i <= n; i++)
        {
            if (m[i] == 0)
                break;
            long long per = last * m[i]; // koi bhi perm. last wale se bnega
            ans += per;
            last = per;
            ans = ans % MOD;
        }
        cout << ans << "\n";
    }

    return 0;
}
