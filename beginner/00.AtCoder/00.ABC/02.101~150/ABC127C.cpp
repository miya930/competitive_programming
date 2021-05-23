#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> l(m), r(m);
    for (int i = 0; i < m; ++i) cin >> l[i] >> r[i];

    vector<ll> d(n+10, 0);
    for (int i = 0; i < m; ++i) {
        d[l[i]]++;
        d[r[i]+1]--;
    } 

    for (int i = 1; i <= n; ++i) d[i] += d[i-1];

    ll count = 0;
    for (int i = 0; i <= n; ++i) {
        if (d[i] == m) count++;
    }
    cout << count << endl;
}
