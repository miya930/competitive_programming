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
    ll b;
    cin >> b;

    if (b == 1) {
        cout << 1 << endl;
        return 0;
    }

    for (ll a = 2; a < 20; a++) {
        if (b%a != 0) continue;
        ll t = b;
        int cnt = 0;
        while((t%a) == 0) {
            t = t / a;
            cnt++;
        }
        if (t == 1 && cnt == a) {
            cout << a << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
