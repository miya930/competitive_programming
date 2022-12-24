#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+k, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = k; i < n+k; ++i) cout << a[i] << " ";
    cout << endl;

    return 0;
}
