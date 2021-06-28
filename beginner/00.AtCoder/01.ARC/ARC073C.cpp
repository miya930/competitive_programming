#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> T(n);
    for (int i = 0; i < n ; ++i) cin >> T[i];

    long long ans = 0;
    long long was = T[0];
    for (int i = 0; i < n; ++i) {
        if (T[i]-was > t) {
            ans += t;
            was = T[i];
        } else {
            ans += T[i] - was;
            was = T[i];
        }
    }
    ans += t;
    cout << ans << endl;
}
