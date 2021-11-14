#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        long long t, L, R;
        cin >> t >> L >> R;
        if (t == 1) {
            l[i] = 2 * L;
            r[i] = 2 * R;
        }
        else if (t == 2) {
            l[i] = 2 * L;
            r[i] = 2 * R - 1;
        }
        else if (t == 3) {
            l[i] = 2 * L + 1;
            r[i] = 2 * R;
        }
        else {
            l[i] = 2 * L + 1;
            r[i] = 2 * R - 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (max(l[i], l[j]) <= min(r[i], r[j])) ans++;
        }
    }
    cout << ans << endl;
}
