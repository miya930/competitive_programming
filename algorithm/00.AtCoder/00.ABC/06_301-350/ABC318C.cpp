#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
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
    int n, d;
    ll p;
    cin >> n >> d >> p;
    vector<ll> f(n);
    for (int i = 0; i < n; i++) cin >> f[i];
    sort(f.rbegin(), f.rend());
    ll ans = 0;
    int cur = 0;
    while(cur < n) {
        int fi = cur;
        int en = min(n-1, cur+d-1);
        ll sum = 0;
        for (int i = fi; i <= en; i++) {
            sum += f[i];
        }
        if (p < sum) {
            ans += p;
            cur = en + 1;
        } else {
            ans += sum;
            cur = en + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
