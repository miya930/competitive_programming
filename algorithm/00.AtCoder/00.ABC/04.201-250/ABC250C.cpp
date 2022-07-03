#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> x(q);
    for (int i = 0; i < q; ++i) {
        cin >> x[i];
        x[i]--;
    }

    map<int,int> mp;
    vector<int> num(n);
    for (int i = 0;i < n; ++i) {
        mp[i] = i;
        num[i] = i;
    }

    for (int i = 0; i < q; ++i) {
        int cur = mp[x[i]];
        int nxt, x2;
        if (cur == n-1) {
            nxt = cur-1;
        } else {
            nxt = cur+1;
        }
        x2 = num[nxt];

        mp[x[i]] = nxt;
        mp[x2]   = cur;
        num[cur] = x2;
        num[nxt] = x[i];
    }

    
    for (auto nx : mp) num[nx.second] = nx.first;
    for (int i = 0;i < n; ++i) cout << num[i]+1 << " ";
    cout << endl;

    return 0;
}
