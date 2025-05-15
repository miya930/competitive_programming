#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
using ll = long long;
using pii = pair<int,int>;
constexpr int inf = 1001001001;
constexpr ll infl = 1LL << 62;
constexpr int dx[] = {1, 0, -1, 0};
constexpr int dy[] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, T b) { return a < b && (a = b, true); };
template<class T> bool chmin(T &a, T b) { return a > b && (a = b, true); };

template <class T> T modpow(T n, T m, T mo) {
    T res = 1;
    while(m > 0) {
        if (m & 1) res = res * n % mo;
        m >>= 1;
        n *= n;
        n %= mo;
    }
    return res;
}

vector<int> pcnt(200010, 0);

int main()
{
    int n;
    string x;
    cin >> n >> x;
    int cnt = 0;
    rep(i, 0, n) {
        if (x[i] == '1') cnt++;
    }

    reverse(x.begin(), x.end());
    
    rep(i, 1, 200010) {
        int pp = __builtin_popcount(i);
        pcnt[i] = pcnt[i % pp] + 1;
    }


    ll tmp1 = 0, tmp2 = 0;
    ll p1 = 1, p2 = 1;
    for (int i = 0; i < n; i++) {
        if (x[i] == '1') {
            tmp1 = (tmp1 + p1) % (cnt + 1);
            if (2 <= cnt) tmp2 = (tmp2 + p2) % (cnt - 1);
        }

        p1 = (p1 * 2) % (cnt + 1);
        if (2 <= cnt) p2 = (p2 * 2) % (cnt - 1);
    }

    vector<int> ans;
    p1 = 1; p2 = 1;
    for (int i = 0; i < n; i++) {
        if (x[i] == '1') {
            if (cnt == 1) {
                ans.push_back(0);
            } else {
                int x = (tmp2 - p2 + cnt - 1) % (cnt - 1);
                ans.push_back(pcnt[x] + 1);
            }
        } else {
            int x = (tmp1 + p1 + cnt + 1) % (cnt + 1);
            ans.push_back(pcnt[x] + 1);
        }

        p1 = (p1 * 2) % (cnt + 1);
        if (2 <= cnt) p2 = (p2 * 2) % (cnt - 1);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) cout << ans[i] << endl;

    return 0;
}
