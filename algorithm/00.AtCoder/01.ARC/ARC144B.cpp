#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> s;
ll n, a, b;
bool check(ll m) {
    vector<ll> t = s;
    sort(t.begin(), t.end());
    ll up = 0;
    ll down = 0;
    for (int i = 0; i < n; i++) {
        if (t[i] < m) {
            up += (m - t[i] + a - 1) / a;
        } else {
            down += (t[i] - m) / b;
        }
    }

    if (up > down) return false;
    else return true;
}

int main()
{
    cin >> n >> a >> b;
    s.resize(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    ll l = 0, r = 1000000001;
    while(r-l > 1) {
        ll mid = (r+l)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}
