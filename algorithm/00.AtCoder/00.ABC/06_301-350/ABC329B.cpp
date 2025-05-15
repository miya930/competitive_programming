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
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    set<int> st;
    map<int,int> mp;
    rep(i, 0, n) {
        st.insert(a[i]);
        mp[a[i]]++;
    }

    int ma1 = 0, ma2 = 0;
    for (auto x : st) {
        if (ma1 < x) {
            ma2 = ma1;
            ma1 = x;
        } else if (ma2 < x) {
            ma2 = x;
        }
    }
    if (ma2 == 0 && mp.size() == 1) {
        for (auto x : mp) {
            if (x.second > 1) ma2 = x.first;
        }
    }
    cout << ma2 << endl;

    return 0;
}
