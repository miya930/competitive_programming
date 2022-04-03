#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m;
    cin >> n >> m;

    ll cor = 4; // 4
    ll ed = 2*(n-2) + 2*(m-2);  // 6
    ll all = n*m - cor - ed;    // 9

    if (n == 1 && m == 1) cout << 1 << endl;
    else if (n == 1) cout << m-2 << endl;
    else if (m == 1) cout << n-2 << endl;
    else  cout << all << endl;
    return 0;
}
