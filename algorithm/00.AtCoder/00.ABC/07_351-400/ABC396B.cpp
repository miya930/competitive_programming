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
    int Q;
    cin >> Q;

    stack<int> st;
    for (int q = 0; q < Q; q++) {
        int c;
        cin >> c;
        if (c == 1) {
            int x;
            cin >> x;
            st.push(x);
        } else {
            if (st.size() > 0) {
                int v = st.top();
                st.pop();
                cout << v << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}
