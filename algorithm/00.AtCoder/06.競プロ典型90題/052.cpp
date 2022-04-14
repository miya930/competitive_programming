#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(n));
    vector<int> b(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) {
            cin >> a[i][j];
            b[i] += a[i][j];
        }
    }

    long long ans = 1;
    for (int i= 0; i < n; ++i) {
        ans *= b[i];
        ans %= MOD;
    }
    cout << ans << endl;
}

/* 2022.4.10 復習 */


#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(6));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) cin >> a[i][j];
    }

    vector<ll> sum(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 6; ++j) sum[i] += a[i][j];
    }

    ll ans = 1;
    for (int i = 0; i < n; ++i) {
        ans *= sum[i];
        ans %= mod;
    }

    cout << ans << endl;
    return 0;
}
