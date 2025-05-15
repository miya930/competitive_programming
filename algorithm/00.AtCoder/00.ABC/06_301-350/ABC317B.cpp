#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < n-1; i++) {
        int tmp = abs(a[i] - a[i+1]);
        if (tmp > 1) {
            cout << a[i] + 1 << endl;
            return 0;
        }
    }

    if (a[0] == 1) {
        cout << a[n-1] + 1 << endl;
    } else if (a[n-1] == 1000) {
        cout << a[0] - 1 << endl;
    }

    return 0;
}
