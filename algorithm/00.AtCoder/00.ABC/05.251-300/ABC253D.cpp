#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> T gcd(T n, T m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

template<class T> T lcm(T n, T m) {
    return n / gcd(n, m) * m;
}

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;

    ll lc = lcm(a, b);

    ll t3 = n/a, t5 = n/b, t15 = n/lc;
    ll sum3 = a*(t3*(t3+1)/2), sum5 = b*(t5*(t5+1)/2), sum15 = lc*(t15*(t15+1)/2);
    
    ll sumall = n*(n+1)/2LL;  

    cout << sumall - (sum3+sum5-sum15) << endl;

    return 0;
}
