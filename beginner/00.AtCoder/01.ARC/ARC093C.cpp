#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n; cin >> n;
    vector<int> a(n+2, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    long long sum = 0;
    for (int i = 0; i <= n; ++i) sum += abs(a[i+1]-a[i]);

    for (int i = 1; i <= n; ++i) {
        long long ans = sum - abs(a[i]-a[i-1]) - abs(a[i+1]-a[i]) + abs(a[i+1]- a[i-1]);
        cout << ans << endl;
    }
    return 0;
}
