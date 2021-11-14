#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int> > t(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> t[i][j];
        }
    }
    
    vector<int> v(n);
    for (int i = 0; i < n; ++i) v[i] = i;

    ll ans = 0;
    do {
        ll sum = 0;
        for (int i = 1; i < n; ++i) {
            sum += t[v[i-1]][v[i]];
        }
        sum += t[v[n-1]][v[0]];
        if (sum == k) ans++;
    } while (next_permutation(v.begin() + 1, v.end()));
    
    cout << ans << endl;
}
