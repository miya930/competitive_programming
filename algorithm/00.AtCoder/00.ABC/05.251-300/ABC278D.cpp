#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pair<ll,int>> pa(n);
    for (int i = 0;i < n; i++) {
        pa[i].first = a[i];
        pa[i].second = 1;
    }

    int Q;
    cin >> Q;
    
    ll que1 = 0;
    int last = 0;

    for (int q = 2; q <= Q+1; q++) {
        int t;
        cin >> t;

        int iq, x;

        if (t == 1) {
            cin >> x;
            que1 = x;
            last = q;

        } else if (t == 2) {
            cin >> iq >> x;
            iq--;

            int last_update = pa[iq].second;
            if (last < last_update) {
                pa[iq].first += x;
            } else {
                pa[iq].first = que1 + x;
            }
            pa[iq].second = q;

        } else {
            cin >> iq;
            iq--;

            int last_update = pa[iq].second;
            if (last < last_update) {
                cout << pa[iq].first << endl;
            } else {
                cout << que1 << endl;
            }
        }
    }

    return 0;
}
