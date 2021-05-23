#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<ll, ll> mp;
    for (int i = 0; i < n; ++i) mp[a[i]]++;

    ll res = 0;
    for (int i = -200; i <= 200; ++i) {
        for (int j = i + 1; j <= 200; ++j) {
            res += (i-j)*(i-j)*mp[i]*mp[j];
        }
    }
    cout << res << endl;
}
