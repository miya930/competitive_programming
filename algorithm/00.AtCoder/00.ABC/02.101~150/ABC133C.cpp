#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 2019;
const int INF = 1000000007;
typedef long long ll;
int r, l;

int solve() {
    int ans = INF;
    for (int i = l; i < r; ++i) {
        for (int j = i + 1; j < r + 1; ++j) {
            ans = min(ans,(int)(1LL * i%MOD * j%MOD));
            if (ans == 0) return 0;
        }
    }
    return ans;
}

int main()
{
    cin >> l >> r;
    cout << solve() << endl;
}