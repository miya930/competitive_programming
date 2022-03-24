#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main(void)
{
    ll a, b, c;
    cin >> a >> b >> c;
    ll tmp = c;
    for (int i = 1; i < b; i++) {
        (c *= tmp) %= MOD;    
    }
    if (c <= (a%MOD))
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}


/*** 2022.3.13 復習 ***/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;

    // c^b / a > 1

    ll tmp = 1;
    for (int i = 0; i < b; ++i) tmp *= c;
    
    if (tmp > a) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
