#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<int,vector<int>> mp;
    map<int,int> cnt;
    for (int i = 0; i < n; ++i) {
        mp[a[i]].push_back(i);
        cnt[a[i]]++;
    }

    for (int q = 0; q < Q; ++q) {
        int x, k;
        cin >> x >> k;

        if (cnt[x] < k) cout << -1 << endl;
        else cout << mp[x][k-1]+1 << endl;
    }

    return 0;
}
