#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll a, b;
    cin >> a >> b;

    if (a%2 != b%2) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << (a+b) / 2 << endl;
    }

    return 0;
}
