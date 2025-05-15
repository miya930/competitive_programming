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
    string s; cin >> s;
    int n = s.size();
    vector<pair<char,int>> pa;
    int cnt = 0;
    char c = s[0];
    rep(i, 0, n) {
        if (c == s[i]) cnt++;
        else {
            pa.push_back(make_pair(s[i-1], cnt));
            cnt = 1;
            c = s[i];
        }
    }
    pa.push_back(make_pair(s[n-1], cnt));

    int m = pa.size();
    rep(i, 1, m) {
        bool isng = false;
        if (pa[i].first == 'A') {
            if (pa[i-1].first == 'C' || pa[i-1].first == 'B') isng = true;
        } else if (pa[i].first == 'B') {
            if (pa[i-1].first == 'C') isng = true;
        }
        if (isng) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
