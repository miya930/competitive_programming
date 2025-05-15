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
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    vector<int> seen(n+1, 0);
    set<int> st;
    rep(i, 0, n) {
        if (a[i] <= n) {
            seen[a[i]]++;
        }
    }
    rep(i, 0, n+1){
        if (seen[i] == 0) {
            st.insert(i);
        }
    }
    rep(q, 0, Q) {
        int i, x;
        cin >> i >> x;
        i--;
        int v = a[i];
        a[i] = x;
        
        if (v <= n) {
            seen[v]--;
            if (seen[v] == 0) {
                st.insert(v);
            }
        }
        if (x <= n) {
            seen[x]++;
            if (seen[x] > 0) {
                st.erase(x);
            }
        }
        cout << *st.begin() << endl;
    }

    return 0;
}
