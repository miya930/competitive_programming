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
    int n = 7;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    map<int,int> mp;
    rep(i, 0, n) mp[a[i]]++;
    int is_two = 0;
    int is_three = 0;
    for (auto v : mp) {
        if (v.second >= 3) {
            is_three++;
            is_two++;
        }
        else if (v.second >= 2) is_two++;
    }
    if (is_two > 1 && is_three > 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
