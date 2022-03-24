#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll GCD(ll n, ll m) {
    if (m == 0) return n;

    return GCD(m, n%m);
}

int main(void)
{
    ll a, b, c;
    cin >> a >> b >> c;

    ll gcd;
    gcd = GCD(a, GCD(b, c));

    cout << a/gcd + b/gcd + c/gcd - 3 << endl;
}

/*** 2022.3.13 競技プログラミング ***/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> T gcd(T n, T m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

int main()
{   
    ll a, b, c;
    cin >> a >> b >> c;

    ll tmp = gcd(a, b);
    ll tmp2 = gcd(c, tmp);

    cout << (a/tmp2-1) + (b/tmp2-1) + (c/tmp2-1) << endl;

    return 0;
}
