#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];

    ll now = 0;
    for (int i = 0; i < n; ++i) {
        ll cur = 1, tmp = t[i];
        ll tmp1 = now;
        while(tmp > 0) {
            cur <<= 1;
            tmp--;
        }

        tmp1 <<= (64-(t[i]+1));
        tmp1 >>= (64-(t[i]+1));

        cur -= tmp1;

        now += cur;
        
    }

    cout << now << endl;
    return 0;
}
