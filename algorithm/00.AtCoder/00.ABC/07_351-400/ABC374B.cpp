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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    if (n != m) {
        for (int i = 0; i < min(n,m); i++) {
            if (s[i] != t[i]) {
                cout << i + 1 << endl;
                return 0;
            }
        }
        cout << min(n, m) + 1 << endl;
        return 0;
    }

    for (int i = 0; i < n; i++){
        if (s[i] != t[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}
