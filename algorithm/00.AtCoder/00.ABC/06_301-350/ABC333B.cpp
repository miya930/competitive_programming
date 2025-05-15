#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
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
    string s, t;
    cin >> s >> t;
    int s1, s2, t1, t2;
    s1 = s[0] - 'A';
    s2 = s[1] - 'A';
    t1 = t[0] - 'A';
    t2 = t[1] - 'A';
    int diff1 = max(s1, s2) - min(s1, s2);
    int diff2 = max(t1, t2) - min(t1, t2);

    if (diff1 > 2) diff1 = 5 - diff1;
    if (diff2 > 2) diff2 = 5 - diff2;

    if (diff1 == diff2) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
