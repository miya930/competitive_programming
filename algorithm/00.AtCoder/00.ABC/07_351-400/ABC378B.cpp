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
    int n;
    cin >> n;
    vector<int> q(n), r(n);
    for (int i = 0; i < n; i++) cin >> q[i] >> r[i];

    int Q;
    cin >> Q;
    for (int qq = 0; qq < Q; qq++) {
        int t, d;
        cin >> t >> d;
        t--;

        ll m = d % q[t];
        if (m <= r[t]) {
            cout << r[t] - m + d << endl;
        } else {
            cout << q[t] - (m - r[t]) + d << endl;
        }
    }
    return 0;
}
