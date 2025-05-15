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

ll d[] = {0, 2, 4, 6, 8};

int main()
{
    ll n;
    cin >> n;
    n--;
    if (n == 0) {
        cout << '0' << endl;
        return 0;
    }

    // 1: 5, 2: 50, 3: 500
    ll num = 5;

    string ans = "";
    while(n > 0) {
        ll mod = n % num;
        ans.push_back('0'+d[mod]);
        n /= num;
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;

    return 0;
}
