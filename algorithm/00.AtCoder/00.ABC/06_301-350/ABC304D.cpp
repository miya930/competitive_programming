#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int w, h, n;
    cin >> w >> h >> n;
    vector<ll> p(n), q(n);
    for (int i = 0; i < n; i++) cin >> p[i] >> q[i];
    ll A; cin >> A;
    vector<ll> a(A);
    for (int i = 0;i < A; i++) cin >> a[i];
    ll B; cin >> B;
    vector<ll> b(B);
    for (int i = 0;i < B; i++) cin >> b[i];

    map<ll,ll> mp;
    for (int i = 0; i < n; i++) {
        ll bli = lower_bound(b.begin(), b.end(), q[i]) - b.begin();
        ll ali = lower_bound(a.begin(), a.end(), p[i]) - a.begin();
        mp[ali*(B+1) + bli]++;
    }

    ll M = 0, m = 1001001001;
    for (auto v : mp) {
        M = max(M, v.second);
        m = min(m, v.second);
    }
    if ((ll)mp.size() < (A+1)*(B+1)) m = 0;
    cout << m << " " << M << endl;
    return 0;
}
