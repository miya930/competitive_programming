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
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    if (n == m) {
        bool ok = true;
        rep(i, 0, n) {
            if (s[i] != t[i]) ok = false;
        }
        if (ok) {
            cout << 0 << endl;
            return 0;
        }
    }

    bool head = true, tail = true;
    rep(i, 0, n){
        if (s[i] != t[i]) {
            head = false;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[n-i-1] != t[m-i-1]) {
            tail = false;
        }
    }
    if (head && tail) cout << 0 << endl;
    else if (head) cout << 1 << endl;
    else if (tail) cout << 2 << endl;
    else cout << 3 << endl;

    return 0;
}
