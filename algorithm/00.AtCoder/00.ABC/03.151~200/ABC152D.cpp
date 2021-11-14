#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    ll n; cin >> n;
    vector<vector<ll> > cnt(10, vector<ll>(10, 0));


    for (int i = 1; i <= n; ++i) {
        int temp = i;
        while (temp >= 10) {
            temp /= 10;
        }
        if (temp != 0) cnt[temp][i%10]++;
    }

    ll ans = 0;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            ans += cnt[i][j] * cnt[j][i];
        }
    }
    
    cout << ans << endl;
    return 0;
}
