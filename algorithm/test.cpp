#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T> T modpow(T n, T m, T mo) {
    T res = 1;
    while(m > 0) {
        if (m & 1) res = res * n % mo;
        m >>= 1;
        n *= n;
        n %= mo;
    }
    return res;
}

template <class T> T moddiv(T n, T mo) {
    return modpow(n, mo-2, mo);
}

template <class T> T modcomb(T n, T r, T mo) {
    T a = 1, b = 1;
    for (T i = 1; i <= n; ++i) {
        a *= i;
        a %= mo;
    }
    for (T i = 1; i <= r; ++i) {
        b *= i;
        b %= mo;
    }
    for (T i = 1; i <= n-r; ++i) {
        b *= i;
        b %= mo;
    }

    return a * moddiv(b, mo) % mo;
}


int main()
{
    cout << power(2, 4) << endl;
    cout << power(4, 3) << endl;

    return 0;
}
