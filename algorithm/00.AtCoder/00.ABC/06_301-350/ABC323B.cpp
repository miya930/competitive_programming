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

bool le(pair<int,int> lh, pair<int,int> rh) {
    if (lh.first != rh.first) return lh.first > rh.first;
    else return lh.second < rh.second;
}

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    vector<int> win(n, 0);
    rep(i, 0, n) {
        rep(j, i+1, n) {
            if (s[i][j]=='o') {
                win[i]++;
            } else {
                win[j]++;
            }
        }
    }

    vector<pair<int,int>> pa;
    rep(i, 0, n) {
        pa.push_back(make_pair(win[i], i));
    }
    sort(pa.begin(), pa.end(), le);
    vector<int> ans;
    rep(i, 0, n) {
        ans.push_back(pa[i].second+1);
    }
    rep(i, 0, n) cout << ans[i] << endl;

    return 0;
}
