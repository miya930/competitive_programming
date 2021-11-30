#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll a, b;
    cin >> a >> b;

    bool flag = false;
    while (a > 0 && b > 0) {
        ll amod = a%10;
        ll bmod = b%10;
        if (amod + bmod >= 10) {
            flag = true;
            break;
        } 
        a /= 10;
        b /= 10;
    }

    if (flag) cout << "Hard" << endl;
    else cout << "Easy" << endl;

    return 0;
}
