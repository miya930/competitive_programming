#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;

ll modpower(ll n, ll m) {
    ll res = 1;
    while(n > 0) {
        if (n & 1) res = res * m % MOD;
        m = m * m % MOD;
        n >>= 1;
    }
    return res;
}

int main()
{
    int n, m;
    cin >> m >> n;

    cout << modpower(n, m) << endl;
    return 0;
}
