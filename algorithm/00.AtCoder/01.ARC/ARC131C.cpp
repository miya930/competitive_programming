#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int xo = 0;
    for (int i = 0; i < n; ++i) xo ^= a[i];

    bool res = false;
    if (n%2 == 1)  res = true;
    else {
        for (int i = 0; i < n; ++i) {
            if ((xo == a[i])) {
                res = true;
            }
        }
    }
    

    if (res) cout << "Win" << endl;
    else cout << "Lose" << endl;

    return 0;
}
