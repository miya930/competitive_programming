#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> bigger(n/2), smaller(n/2);
    for (int i = 0 ; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < n/2; ++i) smaller[i] = a[i];

    int middle;
    if (n%2==1) middle = a[n/2];
    
    sort(a.rbegin(), a.rend());

    for (int i = 0; i < n/2; ++i) bigger[i] = a[i];
    
    vector<int> ans(n);

    sort(smaller.begin(), smaller.end());
    sort(bigger.begin(), bigger.end());

    for (int i = 0; i < n; ++i) {
        if (n%2==1 && i == n-1) break;
        if (i%2==0) ans[i] = bigger[i/2];
        else ans[i] = smaller[i/2];
    }

    if (n%2 == 1) {
        int diff1 = abs(ans[0] - middle);
        int diff2 = abs(ans[n-2] - middle);

        if (diff1 < diff2) ans[n-1] = middle;
        else ans.insert(ans.begin(), middle);
    }

    ll ret = 0;
    for (int i = 1; i < n; ++i) {
        ret += abs(ans[i]-ans[i-1]);
    }

    cout << ret << endl;

    return 0;
}
