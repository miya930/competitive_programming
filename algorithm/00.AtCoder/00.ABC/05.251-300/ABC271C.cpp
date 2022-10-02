#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<bool> vol(n+2, false);
    int sold = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > n) sold++;
        else if (vol[a[i]]) sold++;
        else vol[a[i]] = true;
    }

    int l = 1, r = n+1;
    while(1) {
        while(vol[l])l++;
        while(r != 0 && !vol[r]) r--;

        if (sold >= 2) {
            sold -= 2;
            vol[l] = true;
        } else {
            if (l >= r) break;
            vol[r] = false;
            sold++;
        }
    }

    cout << l-1 << endl;

    return 0;
}
