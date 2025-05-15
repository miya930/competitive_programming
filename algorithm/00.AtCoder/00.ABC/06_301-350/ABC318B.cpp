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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0;  i < n; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
    vector<vector<bool>> s(110, vector<bool>(110, false));
    for (int i = 0; i < n; i++) {
        int x1 = a[i];
        int x2 = b[i];
        int y1 = c[i];
        int y2 = d[i];
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                s[x][y] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (s[i][j]) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
