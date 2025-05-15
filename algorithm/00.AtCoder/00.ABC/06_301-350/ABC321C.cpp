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

vector<string> ans;

void func(string s) {
    int n = s.size();
    int las = s[0] - '0';
    ans.push_back(s);
    reverse(s.begin(), s.end());
    rep(i, las+1, 10) {
        string str = s;
        str.push_back(i + '0');
        reverse(str.begin(), str.end());
        func(str);
    }
}

int main()
{
    int k;
    cin >> k;

    rep(i, 0, 10) {
        string str = "";
        str.push_back(i + '0');
        func(str);
    }
    vector<ll> num;
    int n = ans.size();
    rep(i, 0, n) {
        reverse(ans[i].begin(), ans[i].end());
        ll dig = 1;
        ll cur = 0;
        if (ans[i] == "0") continue;
        rep(j, 0, (int)ans[i].size()) {
            cur += dig * (ans[i][j] - '0');
            dig *= 10;
        }
        num.push_back(cur);
    }
    sort(num.begin(), num.end());
    cout << num[k-1] << endl;

    return 0;
}
