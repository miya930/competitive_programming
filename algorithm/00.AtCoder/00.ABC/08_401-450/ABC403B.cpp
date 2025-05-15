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
    string t, u;
    cin >> t >> u;

    int n = t.size();
    int m = u.size();
    for (int i = 0; i < n-m+1; i++) {
        bool isok = true;
        for (int j = 0; j < m; j++) {
            if (t[i+j] == '?') continue;
            if (t[i+j] != u[j]) {
                isok = false;
            }
        }
        if (isok) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
