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
    int n, Q;
    cin >> n >> Q;
    deque<pair<int,int>> deq;
    rep(i, 1, n+1) {
        deq.push_front(make_pair(i, 0));
    }

    for (int q = 0; q < Q; q++) {
        int t;
        cin >> t;
        if (t == 1) {
            char c;
            cin >> c;
            int cx = deq[n-1].first;
            int cy = deq[n-1].second;
            if (c == 'R') deq.push_back({cx+1,cy});
            if (c == 'L') deq.push_back({cx-1,cy});
            if (c == 'U') deq.push_back({cx, cy+1});
            if (c == 'D') deq.push_back({cx, cy-1});
            deq.pop_front();
        } else if (t == 2) {
            int p;
            cin >> p;
            p--;
            cout << deq[n-p-1].first << " " << deq[n-p-1].second << endl;
        }
    }

    return 0;
}
