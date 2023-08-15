#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n-1; i++) {
        int diff = t[i+1] - t[i];

        if (diff <= d) {
            cout << t[i+1] << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
