#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    vector<ll> a(n, 0);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - sum;
        sum += a[i];
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl; 

    return 0;
}
