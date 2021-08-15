#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    /*
     * ビットごとに任意の2つの数字を選ぶことを考える。
     * k桁目に着目した時、一方が0でもう一方が1なら 2^k が答えに加算される
     * a[0] ~ a[n-1]で 0 がzero個、 1 が one個だとすると、zero×one×2^k が答えに加算されることになる。
     */
    int x = 0;
    ll ans = 0;
    for (int i = 0; i < 60; ++i) {
        ll x = 0;
        for (int j = 0; j < n; ++j) if (a[j]>>i & 1) x++;
        ll now = x * (n-x) % mod;
        for (int j = 0; j < i; ++j) now = now*2 % mod; 
        ans += now;
        ans %= mod;
    } 
    cout << ans << endl;
    return 0;
}
