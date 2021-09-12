#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    ll x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) x += (a[i]-b[i]);
        else y += (b[i]-a[i])/2;
    }

    if (x <= y) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
