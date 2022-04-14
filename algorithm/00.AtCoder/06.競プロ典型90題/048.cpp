/**
  * 
  * ���v���T�^90��
  * 048 - I will not drop out
  * link : https://atcoder.jp/contests/typical90/tasks/typical90_av
  * 
  */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    vector<int> c(2*n+2,0);
    for (int i = 0; i < n; i++) {
        c[i] = b[i];
        c[i+n] = a[i] - b[i];
    }
    sort(c.rbegin(), c.rend());

    ll ans = 0;
    for (int i = 0; i < k; ++i) ans += c[i];
    cout << ans << endl;
}


/* 2022.4.10 復習 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n), vec;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    for (int i = 0; i < n; ++i) {
        vec.push_back(a[i]-b[i]);
        vec.push_back(b[i]);
    }
    sort(vec.rbegin(), vec.rend());
    ll ans = 0;
    for (int i = 0; i < k; ++i) ans += vec[i];

    cout << ans << endl;
    return 0;
}
