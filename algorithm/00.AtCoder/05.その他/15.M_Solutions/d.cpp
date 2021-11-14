/**
   created: 23.10.2021 18:42:01
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    bool flag = true;

    ll mins = a[0], maxs = 0;
    ll money = 1000;
    ll stock = 0;

    for (int i = 0; i < n-1; ++i) {
        if (flag) {
            if (a[i] < a[i+1]) {
                flag = false;
                stock = money/mins;
                money -= stock*mins;
                maxs = a[i+1];
            } else {
                mins = min(mins, a[i+1]);
            }
        } else {
            if (a[i] > a[i+1]) {
                flag = true;
                money += stock*maxs;
                stock = 0;
                mins = a[i+1];
            } else {
                maxs = max(maxs, a[i+1]);
            }
        }
    }

    if (stock > 0) {
        money += stock*maxs;
    }

    cout << money << endl;

    return 0;
}
