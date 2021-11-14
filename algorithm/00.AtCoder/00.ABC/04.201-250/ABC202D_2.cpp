#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

#define CMAX 1010
vector<vector<ll> > memo(CMAX, vector<ll>(CMAX));

ll aCb(ll a, ll b) {
    if (b == 0 || a == b) return 1;
    if (0 <= memo[a][b]) return memo[a][b];
    return memo[a][b] = aCb(a-1, b-1) + aCb(a-1, b);
}

int main()
{
    int a, b;
    ll k;
    cin >> a >> b >> k;
    k--;
    for (int i = 0; i < CMAX; ++i) {
        for (int j = 0; j < CMAX; ++j) {
            memo[i][j] = -1;
        }
    }

    int n = a + b;

    string ans = "";
    for (int i = 0; i < n; ++i) {
        if (a > 0) {
            if (k < aCb(a + b - 1, b)) {
                ans += 'a';
                a--;
            } else {
                ans += 'b';
                k -= aCb(a+b-1, b);
                b--;
            }
        }
        else {
            ans += "b";
            b--;
        }
    }
    cout << ans << endl;
}
