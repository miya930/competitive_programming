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
    vector<int> cell(9, 0);
    rep(i, 0, 9) cin >> cell[i];
    vector<tuple<int,int,int>> row{{0, 1, 2},
                                   {3, 4, 5},
                                   {6, 7, 8},
                                   {0, 3, 6},
                                   {1, 4, 7},
                                   {2, 5, 8},
                                   {0, 4, 8},
                                   {2, 4, 6}};
    vector<int> order(9);
    rep(i, 0, 9) order[i] = i;

    int ans = 0, all = 0;
    do {
        all++;
        bool ng = false;
        for (auto &&[a, b, c] : row) {
            if (cell[a] == cell[b] && order[a] < order[c] && order[b] < order[c]) {
                ng = true;
            }
            if (cell[b] == cell[c] && order[b] < order[a] && order[c] < order[a]) {
                ng = true;
            }
            if (cell[c] == cell[a] && order[c] < order[b] && order[a] < order[b]) {
                ng = true;
            }
        }
        if (!ng) ans++;
    } while(next_permutation(order.begin(), order.end()));

    printf("%.14lf\n", (double)ans / (double)all);

    return 0;
}
