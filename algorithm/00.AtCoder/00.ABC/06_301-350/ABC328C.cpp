#include <bits/stdc++.h>
using namespace std;
#define rep(i, fi, n) for (int i = fi; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };


int main()
{
    int n, Q;
    string s;
    cin >> n >> Q >> s;
    vector<int> sum(n+1, 0);
    rep(i, 0, n-1) {
        if (s[i] == s[i+1]) sum[i+1] = sum[i] + 1;
        else sum[i+1] = sum[i];
    }

    rep(q, 0, Q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << sum[r] - sum[l] << endl;
    }

    return 0;
}
