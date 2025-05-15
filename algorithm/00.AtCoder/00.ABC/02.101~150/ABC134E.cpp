#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    multiset<int> st;
    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            st.insert(-a[i]);
        } else {
            auto it = st.upper_bound(-a[i]);
            if (it == st.end()) {
                st.insert(-a[i]);
            } else {
                st.erase(it);
                st.insert(-a[i]);
            }
        }
    }
    cout << st.size() << endl;

    return 0;
}
