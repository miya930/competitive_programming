#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
const int mod = 998244353;

vector<bool> visit(200500, false);

ll modfac(ll n, ll m) {
    ll res = 1;
    while(n > 0) {
        if (n&1) res = res * m % mod;
        m *= m;
        m %= mod;
        n >>= 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        int f; cin >> f;
        f--;
        vec[i] = f;
    }

    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        map<int, int> mp;
        if (visit[i] == true) continue;
        
        int temp = i;
        bool ok = true;
        mp[i]++;
        while(1) {
            if (mp[temp] > 1) break;
            if (visit[temp] == true) {
                ok = false;
                break;
            }

            visit[temp] = true;
            temp = vec[temp];
            mp[temp]++;
            
        }
        if (ok) sum++;
    }
    
    ll ans = modfac(sum, 2) - 1;
    cout << (ans + mod) % mod << endl;

}
