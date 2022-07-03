#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
        b[i]--;
    }

    map<int, vector<int>> mp;
    map<int,int> ng;
    for (int i = 0; i < n; ++i) {
        mp[a[i]].push_back(i);
    }
    for (int i = 0; i < k; ++i) {
        ng[b[i]]++;
    }

    int ma = 0;
    for (auto x : mp) {
        ma = max(ma, x.first);
    }

    bool flg = true;
    for (auto x : mp[ma]) {
        if (ng[x] == 1) flg = false; 
    }

    if (flg) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
