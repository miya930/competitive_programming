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

ll calc(string &s, string &t) {
    ll g = 0;
    for (auto c : s) {
        if (g >= t.size()) break;
        if (c == t[g]) g++;
    }
    return g;
}

vector<ll> a(500002), b(500002), c(500002);

int main()
{
    int n;
    string t;
    cin >> n >> t;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];

    rep(i, 0, n) a[i] = calc(s[i], t);
    reverse(t.begin(), t.end());

    rep(i, 0, n) {
        reverse(s[i].begin(), s[i].end());
        b[i] = calc(s[i], t);
        c[b[i]]++;
    }
    ll ans = 0;
    rep(i, 0, n) {
        ll l = (ll)t.size() - a[i];
        for (ll j = l; j <= t.size(); j++) {
            ans += c[j];
        }
    }
    cout << ans << endl;

    return 0;
}
