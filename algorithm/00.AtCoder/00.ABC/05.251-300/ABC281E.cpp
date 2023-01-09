#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    multiset<ll> st1, st2;
    vector<ll> b;
    for (int i = 0; i < m; i++) {
        b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < k; i++) st1.insert(b[i]);
    for (int i = k; i < m; i++) st2.insert(b[i]);

    ll sum = 0;
    for (int i = 0; i < k; i++) sum += b[i];
    for (int i = 0; i < n-m+1; i++) {
        if (i != 0) {
            auto itr1 = st1.lower_bound(a[i-1]);

            if (itr1 == st1.end()) {
                st2.erase(a[i-1]);

                int tmp2 = *st1.rbegin();
                if (tmp2 <= a[i+m-1]) {
                    st2.insert(a[i+m-1]);
                } else {
                    auto itr = st1.lower_bound(tmp2);
                    st1.insert(a[i+m-1]);
                    st2.insert(tmp2);
                    st1.erase(itr);

                    sum -= tmp2;
                    sum += a[i+m-1];
                }
            } else {
                st1.erase(itr1);
                st2.insert(a[i+m-1]);
                auto tmp = *st2.begin();
                auto itr = st2.lower_bound(tmp);
                st1.insert(tmp);
                st2.erase(itr);
                sum -= a[i-1];
                sum += tmp;                
            }
        }
        cout << sum << " ";
    }

    cout << endl;

    return 0;
}
