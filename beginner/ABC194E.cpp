#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0 ;i < n; ++i) cin >> a[i];

    map<int, int> mp;
    priority_queue<int> que;
    vector<int> used(n);

    for (int i = 0; i < n; ++i) used[a[i]]++;

    for (int i = 0;i < m; ++i) {
        mp[a[i]]++;
        que.push(a[i]);
    }

    int ans = inf;
    for (int i = 0; i < n; ++i) {
        int v = que.top(); que.pop();
        
    }


    return 0;
}
