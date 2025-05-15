#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,pair<int,int>>> pa(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pa[i].first = abs(a - b);
        pa[i].second.first = a;
        pa[i].second.second = b;
        if (a > b) cnt++;
    }

    if (cnt%2 == 0) {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(pa[i].second.first, pa[i].second.second);
        }
        cout << ans << endl;
        return 0;
    }
    
    sort(pa.begin(), pa.end());

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) sum += min(pa[i].second.first, pa[i].second.second);
        else sum += max(pa[i].second.first, pa[i].second.second);
    }
    cout << sum << endl;

    return 0;
}
