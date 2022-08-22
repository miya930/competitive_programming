#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m, x, t, d;
    cin >> n >> m >> x >> t >> d;

    int ini = t - x * d;

    cout << ini + min(x, m) * d << endl;

    return 0;
}
