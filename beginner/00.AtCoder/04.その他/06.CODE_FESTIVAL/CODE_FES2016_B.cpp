#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main()
{
    ll n; cin >> n;
    vector<ll> sum(n+1, 0);
    for (int i = 1; i <= n; ++i) sum[i] = sum[i-1] + i;

    int res;
    int index;
    for (int i = 1; i < (int)sum.size(); ++i) {
        if (sum[i] >= n) {
            res = sum[i] - n;
            index = i;
            break;
        }
    }

    for (int i = 1; i <= index; ++i) {
        if (i == res) continue;
        cout << i << endl;
    }
    return 0;
}
