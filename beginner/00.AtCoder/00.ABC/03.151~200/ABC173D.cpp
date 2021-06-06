#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.rbegin(), a.rend());

    int head = a[0];

    ll ans = 0;

    for (int i = 1; i <= (n+1)/2 - 1; ++i) {
        ans += min(head, a[i-1]);
    }
    
    for (int i = 0; i < (n+1)/2 - 1; ++i) {
        ans += min(a[i], a[i+1]);
    }

    if (n%2 == 0) ans += min(head, a[n/2-1]);

    cout << ans << endl;
}
