#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

const int MAX = 30;
ll dp[MAX + 1][MAX + 1];

string find_kth(int a, int b, ll k) {
    if (a == 0) return string(b, 'b');
    if (b == 0) return string(a, 'a');
    if (k <= dp[a-1][b]) return string("a") + find_kth(a-1, b, k);
    else return string("b") + find_kth(a, b-1, k-dp[a-1][b]);
}

int main()
{
    ll a, b, k;
    cin >> a >> b >> k;

    dp[0][0] = 1;
    for (int i = 0; i <= a; ++i) {
        for (int j = 0; j <= b; ++j) {
            if (i > 0) {
                dp[i][j] += dp[i-1][j];
            }
            if (j > 0) {
                dp[i][j] += dp[i][j-1];
            }
        }
    }
    cout << find_kth(a, b, k) << endl;
    return 0;
}
