#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k; cin >> n >> k;
    vector<ll> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<ll> b(n);
    for (int i = 0; i < n; ++i) b[i] = a[i];

    ll div = k / n;
    ll k_prime = k%n;

    sort(b.begin(), b.end());

    if (k_prime == 0) {
        for (int i = 0; i < n; ++i) {
            cout << div << endl;
        }
        return 0;
    }

    ll memo = b[k_prime-1];

    for (int i = 0; i < n; ++i) {
        if (a[i] > memo) cout << div << endl;
        else cout << div + 1 << endl;
    }
    
    return 0;
}
