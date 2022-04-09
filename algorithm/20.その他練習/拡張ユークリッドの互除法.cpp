#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* 参考URL：https://qiita.com/drken/items/b97ff231e43bce50199a#3-3-ax--by--gcda-b-%E3%81%AE%E6%95%B4%E6%95%B0%E8%A7%A3%E3%81%8C%E5%AD%98%E5%9C%A8%E3%81%99%E3%82%8B%E3%81%93%E3%81%A8%E3%81%AE%E4%B8%80%E8%88%AC%E8%AB%96 */
ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD (b, a%b, y, x);
    y -= a/b * x;
    return d;
}

int main()
{
    ll x, y;
    extGCD(111, 30, x, y);

    cout << x << " " << y << endl;
    return 0;
}
