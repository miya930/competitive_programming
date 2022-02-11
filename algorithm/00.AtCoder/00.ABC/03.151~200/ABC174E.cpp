#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1001001001;

vector<int> a;

bool check(ll mid, int k) {
    ll sum = 0;
    int si = a.size();
    for (int i = 0; i < si; ++i) {
        sum += ((a[i]+mid-1)/mid-1);
    }

    if (sum > k) return false;
    else return true;
}

int main()
{
    int n, k;
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll r = inf, l = 0;

    while(r - l > 1) {
        ll mid = (r+l)/2;
        if (check(mid, k)) r = mid;
        else l = mid;
    }

    cout << r << endl;
    return 0;
}
