#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll ma = 1001001001;
vector<bool> vec(ma+1, true);

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = 0;
    map<ll,int> mp;
    for (int i = 0; i < n; ++i) {
        ll tmp = 2*a[i];
        while(1) {
            if (tmp >= ma) break;
            vec[tmp] = false;
            tmp *= 2;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (vec[a[i]]) ans++;
    }
    
    cout << ans << endl;
    return 0;
}
