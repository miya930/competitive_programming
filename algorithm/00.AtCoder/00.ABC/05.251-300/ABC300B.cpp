#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> a(h), b(h);
    for (int i = 0; i < h; i++) cin >> a[i];
    for (int i = 0; i < h; i++) cin >> b[i];

    for (int s = 0; s < h; s++) {
        for (int t = 0; t < w; t++) {
            bool isok = true;
            for (int y = 0; y < h; y++) {
                for (int x = 0; x < w; x++) {
                    if (a[(y+s)%h][(x+t)%w] != b[y][x]) isok = false;
                }
            }

            if (isok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
