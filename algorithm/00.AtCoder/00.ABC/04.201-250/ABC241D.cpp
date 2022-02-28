#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int Q;
    cin >> Q;

    multiset<ll> st;

    for (int q = 0; q < Q; ++q) {
        int t; cin >> t;

        if (t == 1) {
            ll x;
            cin >> x;
            st.insert(x);

        } else if (t == 2) {
            ll x;
            int k;
            cin >> x >> k;

            auto itr = st.upper_bound(x);
            bool flag = false;

            for (int i = 0; i < k; ++i) {
                if (itr == st.begin()) {
                    flag = true;
                    break;
                }
                itr--;
            }

            if (flag) cout << -1 << endl;
            else cout << *itr << endl;

        } else {
            ll x;
            int k;
            cin >> x >> k;

            auto itr = st.lower_bound(x);
            bool flag = false;
            for (int i = 0; i < k-1; ++i) {
                if (itr == st.end()) {
                    flag = true;
                    break;
                }
                itr++;
            }
             
            if (flag || itr == st.end()) cout << -1 << endl;
            else cout << *itr << endl;
        }
    }

    return 0;
}
