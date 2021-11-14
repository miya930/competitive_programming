/**
   created: 18.10.2021 22:29:31
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

ll patty[51], tot[51];

ll f(int level, ll x) {
    if (level == 0) return 1;

    if (x < 1) return 0;
    x--;

    if (x < tot[level-1]) return f(level-1, x);
    x -= tot[level-1];

    if (x < 1) return patty[level-1] + 1;
    x--;

    if (x < tot[level-1]) return patty[level-1] + 1 + f(level-1, x);
    x -= tot[level-1];

    return patty[level - 1]*2 + 1;

}

int main()
{
    int n;
    ll x;
    cin >> n >> x;
    x--;

    tot[0] = 1;
    for (int i = 1; i <= n; ++i) tot[i] = tot[i-1]*2 + 3;

    patty[0] = 1;
    for (int i = 1; i <= n; ++i) patty[i] = patty[i-1]*2+1;
    
    cout << f(n, x) << endl;

    return 0;
}
