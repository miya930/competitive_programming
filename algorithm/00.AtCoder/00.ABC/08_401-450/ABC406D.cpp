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

vector<bool> rem_row(200010), rem_col(200010);

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];
    map<int,int> row, col;
    map<int, vector<int>> r, c;
    rep(i, 0, n){
        row[x[i]]++;
        col[y[i]]++;
        r[x[i]].push_back(y[i]);
        c[y[i]].push_back(x[i]);
    }
    int Q;
    cin >> Q;
    rep(q, 0, Q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x; cin >> x;
            if (rem_row[x]) cout << 0 <<endl;
            else {
                vector<int> vec = r[x];
                if (vec.size() == 0) {
                    cout << 0 << endl;
                    continue;
                }
                for (auto nv : vec) {
                    col[nv]--;
                }
                cout << row[x] << endl;
                rem_row[x] = true;
            }
        } else {
            int y; cin >> y;
            if (rem_col[y]) cout << 0 << endl;
            else {
                vector<int> vec = c[y];
                if (vec.size() == 0) {
                    cout << 0 << endl;
                    continue;
                }
                for (auto nv : vec) {
                    row[nv]--;
                }
                cout << col[y] << endl;
                rem_col[y] = true;                
            }
        }
    }

    return 0;
}
