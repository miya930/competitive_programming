/**
   created: 23.10.2021 08:44:47
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    double n, m;
    cin >> n >> m;

    ll ans = m*1900+(n-m)*100;
    ll two = 1;
    for (int i = 0; i < m; ++i) {
        two *= 2;
    }

    cout << ans * two << endl;

    return 0;
}
