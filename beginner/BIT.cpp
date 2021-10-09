/***
 * BITの実装
 * 参考HP：https://qiita.com/DaikiSuyama/items/7295f5160a51684554a7
 * 
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

class BIT {
public:
    ll n;
    vector<ll> a;
    
    BIT(ll n): n(n), a(n+1, 0) {}

    // a[i]にxを加算する
    void add(ll i, ll x) {
        i++;
        if (i==0) return;
        for (ll k = i; k <= n; K += (k & -k)) { // k & -kはLSBを表す。試に紙に書いてみるとわかる
            a[k] += x;
        }
    }

    ll sum(ll i, ll j) {
        return sum_sub(j)-sum_sub(i-1);
    }

    // a[0]+a[1]+~+a[i]を求める
    ll sum_sub(ll i) {
        i++;
        ll s = 0;
        if (i == 0) return s;
        for (ll k = i; k > 0; k-=(k & -k)) {
            s += a[k];
        }
        return s;
    }
}