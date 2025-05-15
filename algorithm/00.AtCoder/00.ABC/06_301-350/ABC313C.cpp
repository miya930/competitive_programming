#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        b[i] = (sum+i) / n;
    }
    sort(b.begin(), b.end());

    ll diff = 0;
    for (int i = 0; i < n; i++) {
        diff += abs(b[i] - a[i]);
    }

    cout << diff / 2L << endl;

    return 0;
}
