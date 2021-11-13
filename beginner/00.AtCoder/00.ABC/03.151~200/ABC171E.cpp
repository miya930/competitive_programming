#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int x = 0;
    for (int i = 0; i < n; ++i) x ^= a[i];

    x ^= a[0];

    for (int i = 0; i < n; ++i) {
        cout << x << " ";
        x ^= a[i];
        if (i != n-1) x ^= a[i+1]; 
    }
    cout << endl;

    return 0;
}
