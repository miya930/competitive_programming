#include <iostream>
#include <vector>
using namespace std;
const int num = 10000100;

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> c(n+1);
    for (int i = 2; i < n; ++i) {
        if(c[i] != 0) continue;
        for (int j = i; j <=n; j += i) c[j]++;
    }

    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (c[i] >= k) ans++;
    }
    cout << ans << endl;
}




/*** 2022.3.13 復習 ***/

#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
vector<int> vec;
vector<bool> isprime;

int main()
{
    int n, k;
    cin >> n >> k;
    vec.assign(n+1, 0);
    isprime.assign(n+1, true);
    isprime[0] = false; isprime[1] = false;

    for (int i = 2; i <= n; ++i) {
        if (isprime[i]==false) continue;
        for (int j = i*2; j <= n; j += i) {
            isprime[j] = false;
        }
    }

    vector<int> prime;
    for (int i = 2; i <= n; ++i) {
        if (isprime[i]) prime.push_back(i);
    }

    int si = prime.size();
    for (int i = 0; i < si; ++i) {
        for (int j = prime[i]; j <= n; j += prime[i]) vec[j]++;
    }

    ll ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (vec[i] >= k) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
