#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int vec[200000];

int main()
{
    int n;
    cin >> n;

    for (int x = 1; x <= 100; x++) {
        for (int y = 1; y <= 100; y++) {
            for (int z = 1; z <= 100; z++) {
                int f = x*x + y*y + z*z + x*y + y*z + z*x;
                vec[f]++;
            }
        }
    }

    for (int i = 1; i <= n; ++i) cout << vec[i] << endl;

    return 0;
}
