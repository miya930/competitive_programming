#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    
    vector<pair<ll,char>> pa(2*n);
    vector<ll> num(3, 0);
    for (int i = 0; i < 2*n; ++i) {
        cin >> pa[i].first >> pa[i].second;
        if (pa[i].second == 'R') num[0]++;
        else if (pa[i].second == 'G') num[1]++;
        else num[2]++;
    }

    if (num[0]%2 == 0 && num[1]%2 == 0 && num[2]%2 == 0) {
        cout << 0 << endl;
        return 0;
    }

    sort(pa.begin(), pa.end());

    ll mi1 = infl, mi2 = infl, mi3 = infl;
    for (int i = 0; i < 2*n-1; ++i) {
        if ((pa[i].second == 'R' && pa[i+1].second == 'G') || (pa[i].second == 'G' && pa[i+1].second == 'R')) mi1 = min(mi1, abs(pa[i].first - pa[i+1].first));
        if ((pa[i].second == 'R' && pa[i+1].second == 'B') || (pa[i].second == 'B' && pa[i+1].second == 'R')) mi2 = min(mi2, abs(pa[i].first - pa[i+1].first));
        if ((pa[i].second == 'G' && pa[i+1].second == 'B') || (pa[i].second == 'B' && pa[i+1].second == 'G')) mi3 = min(mi3, abs(pa[i].first - pa[i+1].first));
    }

    ll ans = infl;

    if (num[0]%2 == 1 && num[1]%2 == 1) {
        ans = min(ans, mi1);
        ans = min(ans, mi2+mi3);
    } else if (num[0]%2 == 1 && num[2]%2 == 1) {
        ans = min(ans, mi2);
        ans = min(ans, mi1+mi3);
    } else {
        ans = min(ans, mi3);
        ans = min(ans, mi1+mi2);
    }

    cout << ans << endl;
    return 0;
}
