#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    ll P, Q, R;
    cin >> n >> P >> Q >> R;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    set<ll> st({0});
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        s += a[i];
        st.insert(s);
    }

    for (auto x : st) {
        if (st.find(x+P) != st.end() && st.find(x+P+Q) != st.end() && st.find(x+P+Q+R) != st.end()) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
