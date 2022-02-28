#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    map<int,int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (int i = 0; i < m; ++i) cin >> b[i];

    bool flag = true;
    for (int i = 0; i < m; ++i) {
        if (mp[b[i]] == 0) flag = false;
        mp[b[i]]--;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
