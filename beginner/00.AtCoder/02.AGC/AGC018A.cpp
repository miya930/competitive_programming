#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int n, int m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0 ; i < n; ++i) cin >> a[i];

    int g;
    int ma = 0;
    if (n > 1) {
        g = gcd(a[0], a[1]);
        ma = max(ma, max(a[1], a[0]));
    } else {
        g = a[0];
        ma = a[0];
    }
    
    for (int i = 2; i < n; ++i) {
        g = gcd(g, a[i]);
        ma = max(ma, a[i]);
    }
    
    if (k%g==0 & ma >= k) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0;

}
