#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<bool> isprime(n+1, true);
    isprime[0] = isprime[1] = false;

    for (int i = 2; i <= n; ++i) {
        for (int j = 2*i; j <= n; j += i) {
            isprime[j] = false;
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (isprime[i]) cout << i << " ";
    }
    
    cout << endl;
    return 0;
}
