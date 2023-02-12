#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> under(200100), num(200100, -1), ans(200100, -1);

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    set<int> st;
    for (int i = 0; i < n; i++) {
        auto itr = st.upper_bound(p[i]);
        if (itr != st.end()) {
            under[p[i]] = *itr;
            num[p[i]] = num[*itr] + 1;
            st.erase(itr);

        } else {
            num[p[i]] = 1;
        }
        st.insert(p[i]);

        if (num[p[i]] == k) {
            int t1 = p[i];
            st.erase(t1);
            for (int j = 0; j < k; j++) {
                ans[t1] = i + 1;
                
                t1 = under[t1];
            }

        }        
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
