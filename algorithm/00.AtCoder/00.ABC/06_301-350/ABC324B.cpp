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
    ll n;
    cin >> n;

    while(n%2 == 0) {
        n /= 2;
    }
    while(n%3 == 0) {
        n /= 3;
    }

    if (n > 1) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
