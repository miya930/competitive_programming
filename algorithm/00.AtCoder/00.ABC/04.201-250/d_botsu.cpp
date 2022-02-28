#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int Q;
    cin >> Q;
    
    priority_queue<ll,vector<ll>, greater<ll>> quemi;
    priority_queue<ll> quema;
    for (int q = 0; q < Q; ++q) {
        int t; cin >> t;
        priority_queue<ll,vector<ll>, greater<ll>> que2;
        priority_queue<ll> que1;

        if (t == 1) {
            ll x; cin >> x;
            quema.push(x);
            quemi.push(x);
        } else if (t == 2) {
            ll x;
            int k;
            cin >> x >> k;

            if (quema.size() < k) cout << -1 << endl;
            else {
                for (int i = 1; i <= 5; ++i) {
                    ll tmp = quema.top();
                    quema.pop();
                    que1.push(tmp);
                    
                    if (i == k) cout << tmp << endl;
                }

                quema = que1;
            }

        } else {
            ll x;
            int k;
            cin >> x >> k;

            if (quemi.size() < k) cout << -1 << endl;
            else {
                for (int i = 1; i <= 5; ++i) {
                    ll tmp = quemi.top();
                    quemi.pop();
                    que2.push(tmp);

                    if (i == k) cout << tmp << endl;
                }

                quemi = que2;
            }
        }
    }

    return 0;
}
