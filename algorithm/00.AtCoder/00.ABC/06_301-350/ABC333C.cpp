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

vector<ll> d = {1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111, 11111111111, 111111111111};
int m;

int main()
{
    int n;
    cin >> n;
    m = d.size();

    set<ll> st;
    rep(i, 0, m) {
        rep(j, 0, m) {
            rep(k, 0, m) {
                ll t = d[i]+d[j]+d[k];
                st.insert(t);
            }
        }
    }

    rep(i, 0, n-1) {
        st.erase(*st.begin());
    }
    cout << *st.begin() << endl;

    return 0;
}
