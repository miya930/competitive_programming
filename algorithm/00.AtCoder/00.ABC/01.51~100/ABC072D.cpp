#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }

    int ans = 0;
    for (int i = 0; i < n-1; ++i) {
        if (p[i] == i) {
            swap(p[i], p[i+1]);
            ans++;
        }
    }

    if (p[n-1] == n-1) {
        swap(p[n-2], p[n-1]);
        ans++;
    }

    cout << ans << endl;
    return 0;
}
