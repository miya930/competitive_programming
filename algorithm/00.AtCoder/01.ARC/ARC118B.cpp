#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

ll k, n, m;
vector<ll> a, b;
vector<ll> le, ri; 

bool check(ll mid) {

    ll lsum = 0, rsum = 0;
    for (int i = 0; i < k; ++i) {

        ll left = (a[i]*m-mid+n-1)/n;
        ll right = (a[i]*m+mid)/n;

        lsum += left;
        rsum += right;
    }

    if (lsum <= m && m <= rsum) return true;
    else return false;
}

void calc(ll mid) {

    ll b_sum = 0;
    for (int i = 0; i < k; ++i) {
        
        le[i] = (a[i]*m-mid+n-1)/n;
        ri[i] = (a[i]*m+mid)/n;

        b[i] = le[i];
        b_sum += b[i];
    }

    for (int i = 0; i < k; ++i) {
        if (b_sum == m) break;

        ll tmp = ri[i] - b[i];
        
        if (b_sum + tmp > m) {
            b[i] += (m-b_sum);
            b_sum = m;
            break;
        } else {
            b[i] = ri[i];
            b_sum += tmp;
        }
    }

    return;
}

int main()
{
    cin >> k >> n >> m;
    a.resize(k); b.resize(k);
    le.resize(k); ri.resize(k);
    for (int i = 0; i < k; ++i) cin >> a[i];

    ll l = 0, r = inf;
    while (r - l > 1) {
        int mid = (r+l)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }

    calc(r);

    for (int i = 0; i < k; ++i) cout << b[i] << " ";
    cout << endl;

    return 0;
}
