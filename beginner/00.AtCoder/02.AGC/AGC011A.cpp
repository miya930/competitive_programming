#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];

    sort(t.begin(), t.end());

    long long ans = 1;
    long long cnt = 1;
    long long first = t[0];
    for (int i = 1; i < n; ++i) {
        if (cnt == c || first+k < t[i]) {
            cnt = 1;
            ans++;
            first = t[i];
        }
        else cnt++;
    }
    cout << ans << endl;
}
