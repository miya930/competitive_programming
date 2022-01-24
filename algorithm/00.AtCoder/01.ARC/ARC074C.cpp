#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;
ll ans = infl;

void solve(ll h, ll w) {
    for (ll i = 1; i < h; ++i) {
        ll s1 = i*w, s2 = (h-i)/2*w, s3 = (h-i+1)/2*w;
        ll diff = max(abs(s1-s2), max(abs(s1-s3), abs(s2-s3)));
        ans = min(ans, diff);

        s2 = w/2*(h-i);
        s3 = (w+1)/2*(h-i);
        diff = max(abs(s1-s2), max(abs(s1-s3), abs(s2-s3)));
        ans = min(ans, diff);
    }

}

int main()
{
    ll h ,w;
    cin >> h >> w;
    
    solve(h, w);
    solve(w, h);

    cout << ans << endl;
    return 0;
}
