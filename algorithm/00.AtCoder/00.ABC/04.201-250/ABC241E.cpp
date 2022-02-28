#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A[200010], S[200010];
int pre[200010];

int main()
{
    int n;
    ll k;
    int s, t, p, b;
    ll a, x;
    ll ans = 0;

    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> A[i];

    for (int i = 0; i < n; ++i) pre[i] = -1;
    S[0] = 0;
    pre[0] = 0;

    for (int i = 0; i < n; ++i) {
        S[i+1] = S[i] + A[S[i] % n];
        if (pre[S[i+1] % n] != -1) {
            s = pre[S[i+1] % n];
            t = i + 1;
            break;
        }
        pre[S[i+1] % n] = i + 1;
    }

    if (k <= s) ans = S[k];
    else {
        p = t - s;
        x = S[t] - S[s];
        a = (k - s - 1) / p;
        b = (k - s - 1) % p;
        ans = S[s + b + 1] + (a*x);
    }

    cout << ans << endl;
    return 0;
}
