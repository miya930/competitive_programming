#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>  a(n+2);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    vector<int> b(n+2,0), c;
    int cnt = 0;
    for (int i = n; i >= 1; --i) {
        int sum = 0;
        for (int j = 2*i; j <= n; j += i) {
            sum += b[j];
        }
        if (sum%2 == a[i]) b[i] = 0;
        else {
            b[i] = 1;
            c.push_back(i);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) ans += b[i];
    cout << ans << endl;

    for (int i = 0; i < c.size(); ++i) cout << c[i] << endl;
    cout << endl;
    return 0;
}
