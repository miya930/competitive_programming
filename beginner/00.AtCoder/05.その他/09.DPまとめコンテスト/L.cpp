#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const ll inf = 1LL << 60;
vector<ll> a;
ll dp[3010][3010];
int vis[3010][3010];
int n;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
}

template<class T> void chmin(T &a, T b) {
    if (a > b) a = b;
}

ll func(int l, int r) {
    if (l>r) return 0;
    if (vis[l][r]) return dp[l][r];
    vis[l][r] = 1;

    ll res = 0;
    ll diff = n - (r - l + 1);
    
    if (diff%2==0) {
        res = -inf;
        chmax(res, func(l+1, r)+a[l]);
        chmax(res, func(l, r-1)+a[r]);
    } else {
        res = inf;
        chmin(res, func(l+1, r)-a[l]);
        chmin(res, func(l, r-1)-a[r]);
    }
    return dp[l][r] = res;
}

int main()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    memset(vis, 0, sizeof(vis));

    cout << func(0, n-1) << endl;
    
}
