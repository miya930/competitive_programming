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
ll mod = 1e9;

int main()
{
    ll n, k;
    cin >> n >> k;
    queue<ll> que;
    ll sum = 0;
    rep(i, 0, n) {
        if (i < k) {
            que.push(1);
            sum += 1;
            sum %= mod;
        } else {
            ll v = que.front();
            que.pop();
            ll an = sum;
            que.push(an);
            sum = (sum - v + an + mod) % mod;
        }
    }
    if(n < k) cout << 1 << endl;
    else cout << sum << endl;
    return 0;
}
