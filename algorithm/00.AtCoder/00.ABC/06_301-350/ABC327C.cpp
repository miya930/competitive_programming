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
    n = 9;
    vector<vector<int>> a(n, vector<int>(n, 0));
    rep(i, 0, n)rep(j, 0, n) cin >> a[i][j];

    bool ng = false;
    // 行チェック
    rep(i, 0, n) {
        set<int> st;
        rep(j, 0, n) {
            st.insert(a[i][j]);
        }
        if (st.size() != 9) ng = true;
    }

    rep(j, 0, n) {
        set<int> st;
        rep(i, 0, n) {
            st.insert(a[i][j]);
        }
        if (st.size() != 9) ng = true;
    }

    for (int x = 0; x < n; x+=3) {
        for (int y = 0; y < n; y+=3) {
            set<int> st;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int nx = x + i;
                    int ny = y + j;
                    st.insert(a[nx][ny]);
                }
            }
            if (st.size() != 9) ng = true;
        }
    }

    if (ng) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
