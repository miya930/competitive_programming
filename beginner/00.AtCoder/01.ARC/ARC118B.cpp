#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
typedef long long ll;
 
int main()
{
    int k, n, m;
    cin >> k >> n >> m;
    vector<ll> a(k);
    for (int i = 0; i < k; ++i) cin >> a[i];
 
    ll sum = 0; ll carry_down = 0;
    vector<tuple<ll, ll, ll, bool>> b(k);
    vector<ll> c(k);
    for (int i = 0; i < k; ++i) {
        get<1>(b[i]) = m * a[i] / n;
        get<2>(b[i]) = n * get<1>(b[i]) - m * a[i];
        get<0>(b[i]) = n * (get<1>(b[i]) + 1) - m * a[i];
        get<3>(b[i]) = true;
        c[i] = get<0>(b[i]);
        sum += get<1>(b[i]);
    }
    carry_down = m - sum;
    sort(c.begin(), c.end());
    
    for (int i = 0; i < carry_down; ++i) {
        for (int j = 0; j < k; ++j) {
            if (get<0>(b[j]) == c[i]) {
                if (get<3>(b[j]) == true) {
                    get<1>(b[j])++;
                    get<3>(b[j]) = false;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < k; ++i) cout << get<1>(b[i]) << " ";
    cout << endl;
}