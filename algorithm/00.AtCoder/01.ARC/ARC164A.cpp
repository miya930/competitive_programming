#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        ll n, k;
        cin >> n >> k;
        ll x = 1;
        ll sum = 0;
        ll nn = n;
        while(nn > 0) {
            sum += nn % 3LL;
            nn /= 3LL;
        }

        if ((n%2 == k%2) && (sum <= k) && (sum <= n)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
