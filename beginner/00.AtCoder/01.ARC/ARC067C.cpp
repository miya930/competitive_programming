#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
using ll = long long;

vector<pair<int, int> > fact(int n) {
    vector<pair<int, int> > res;
    for (int i = 2; i*i <= n; ++i) {
        if (n%i != 0) continue;
        int ex = 0;
        while (n%i == 0) {
            ex++;
            n /= i;
        }
        res.push_back(make_pair(i, ex));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> vec(n+1, 0);
    
    ll ans = 1;
    for (int i = 2;i <= n; ++i) {
        vector<pair<int, int> > pr = fact(i);
        for (auto x : pr) {
            vec[x.first] += x.second;
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (vec[i] != 0) {
            ans *= (vec[i]+1);
            ans %= mod;
        }
    }
    
    cout << ans << endl;
    return 0;
}
