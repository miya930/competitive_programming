/**
   created: 21.10.2021 23:26:54
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;

    if (c-a-b <= 0) {
        cout << "No" << endl;
        return 0;
    }

    ll temp = c - a - b;

    if (4*a*b < temp*temp) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
