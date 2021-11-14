/**
   created: 17.10.2021 19:40:59
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
    for (int i = 0 ;i < n; ++i) cin >> a[i];

    vector<ll> ans(n);

    double silver = 0;
    double gold = 1;
    bool isgold = true;
    for (int i = 0; i < n-1; ++i) {
        if (isgold) {
            if (a[i] > a[i+1]) {
                isgold = false;
                silver = gold * (double)a[i];
                gold = 0;
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
        } else {
            if (a[i] < a[i+1]) {
                isgold = true;
                gold = silver / a[i];
                silver = 0;
                ans[i] = 1;
            } else {
                ans[i] = 0;
            }
        }
    }

    if (!isgold) ans[n-1] = 1;
    

    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << endl;

    return 0;
}
