#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int mod = 998244353;

int main()
{
    int n;
    cin >> n;

    vector<long long> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        if (i == 0 && d[i] != 0) {
            cout << 0 << endl;
            return 0;
        }
        if (i != 0 && d[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    map<long long, long long> mp;
    for (int i = 0; i < n; ++i) mp[d[i]]++;

    long long ans = 1;
    for (int i = 1; i < n; ++i) {
        ans *= mp[d[i]-1];
        ans %= mod;
        for (int j = 0; j < i; ++j) {

        }
    }
    cout << ans << endl;
}