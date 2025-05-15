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

bool les(pair<int,int> lhs, pair<int,int> rhs) {
    if (lhs.first != rhs.first) return lhs.first < rhs.first;
    else return lhs.second < rhs.second;
}

int main()
{
    int n;
    cin >> n;
    vector<int> d(2*n);
    rep(i, 0, n) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        d[a] = i; d[b] = i;
    } 
    stack<int> st;
    rep(i, 0, 2*n) {
        int t = d[i];
        if (!st.empty()) {
            if (st.top() == t) st.pop();
            else st.push(t);
        } else {
            st.push(t);
        }
    }
    if (st.empty()) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
