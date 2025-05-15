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

vector<map<int,bool>> mp(200010);
map<int, bool> all_per;

int main()
{
    int n, m, Q;   
    cin >> n >> m >> Q;
    for (int q = 0; q < Q; q++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x,y;
            cin >> x >> y;
            x--; y--;
            mp[x][y] = true;
        } else if (t == 2) {
            int x;
            cin >> x;
            x--;
            all_per[x] = true;
        } else {
            int x, y;
            cin >> x >> y;
            x--; y--;

            if (all_per.count(x) > 0 || mp[x].count(y) > 0) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
