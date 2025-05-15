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
    int Q;
    cin >> Q;
    queue<int> que;
    rep(q, 0, Q) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            que.push(x);
        } else {
            int x = que.front();
            que.pop();
            cout << x << endl;
        }
    }   

    return 0;
}
