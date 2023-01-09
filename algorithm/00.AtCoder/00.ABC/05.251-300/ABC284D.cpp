#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll ma = 1e10;

bool check(ll m, ll val) {
    if (m*m >= val) return true;
    else return false; 
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        ll n;
        cin >> n;

        ll p = 0, q = 0;
        for (ll i = 2; i*i <= 1e13; i++) {
            if (n%i != 0) continue;
            n /= i;
            
            if (n%i == 0) {
                p = i;
                q = n/i;
            } else {
                q = i;

                ll l = 1, r = ma;
                while(r-l > 1) {
                    ll m = (r+l) / 2;
                    if (check(m, n)) r = m;
                    else l = m;
                }

                p = r;
            }

            break;
        }
        cout << p << " " << q << endl;
    }

    return 0;
}
