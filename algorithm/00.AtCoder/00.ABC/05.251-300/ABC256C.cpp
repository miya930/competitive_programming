#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h1, h2, h3, w1, w2, w3;
    cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    int ans = 0;
    for (int i1 = 1; i1 <= 30; i1++) {
        for (int i2 = 1; i2 <= 30; i2++) {
            for (int i3 = 1; i3 <= 30; i3++) {
                for (int i4 = 1; i4 <= 30; i4++) {
                    int a13 = h1 - i1 - i2;
                    int a23 = h2 - i3 - i4;
                    int a31 = w1 - i1 - i3;
                    int a32 = w2 - i2 - i4;
                    if (a13 < 1 || a13 > 30) continue;
                    if (a23 < 1 || a23 > 30) continue;
                    if (a31 < 1 || a31 > 30) continue;
                    if (a32 < 1 || a32 > 30) continue;

                    int a33 = h3 - a31 - a32;
                    int a33_2 = w3 - a13 - a23;

                    if (a33 < 1 || a33 > 30) continue;
                    if (a33 != a33_2) continue;

                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
