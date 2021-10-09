/**
   created: 09.10.2021 16:59:09
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;
const int maxn = 1000100;

template<class T> T gcd(T n, T m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0;  i< n; ++i) cin >> a[i];

    // pairwise coprime 判定
    vector<int> vec(maxn, false);

    for (int i = 0; i < n; ++i) vec[a[i]]++;

    bool pairwise = true;
    for (int i = 2; i < maxn; ++i) {
        int cnt = 0;
        for (int j = i; j < maxn; j += i) {
            if (vec[j]) {
                cnt += vec[j];
            }
        }

        if (cnt > 1) pairwise = false;
    }

    if (pairwise) {
        cout << "pairwise coprime" << endl;
        return 0;
    }

    // setwise coprime 判定
    ll setwise = a[0];
    for (int i = 0; i < n; ++i) {
        ll gc = setwise;
        setwise = gcd(gc, a[i]);
    }

    if (setwise == 1) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;

    return 0;
}
