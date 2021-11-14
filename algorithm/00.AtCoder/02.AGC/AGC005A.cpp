/**
   created: 11.10.2021 22:48:46
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    string x;
    cin >> x;

    int n = (int)x.size();

    int cnts = 0;
    int ans = n;
    for (int i = 0; i < n; ++i) {
        if (x[i] == 'S') cnts++;
        else if (x[i] == 'T') {
            if (cnts > 0) {
                ans -= 2;
                cnts--;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
