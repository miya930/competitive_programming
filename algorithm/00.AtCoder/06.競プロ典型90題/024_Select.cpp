#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    ll res = 0;

    for (int i = 0; i < N; ++i) 
        res += abs(A[i]-B[i]);

    if ((res > K) || (res%2 != K%2))
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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    
    ll sum = 0;
    for (int i = 0; i < n; ++i) sum += abs(a[i]-b[i]);

    if (sum > k || sum%2 != k%2) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
