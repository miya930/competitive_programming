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
    int r, x;
    cin >> r >> x;

    if (x == 1) {
        if (r >= 1600 && r <= 2999) {
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
    } else {
        if (r >= 1200 && r <= 2399) {
            cout << "Yes" << endl;
        }else {
            cout << "No" << endl;
        }
    }

    return 0;
}
