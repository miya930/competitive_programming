#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    bool flg = true;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (a[i][j] == 'W' && a[j][i] == 'L') continue;
            else if (a[i][j] == 'L' && a[j][i] == 'W') continue;
            else if (a[i][j] == 'D' && a[j][i] == 'D') continue;
            else {
                flg = false;
                break;
            }
        }
    }

    if (flg) cout << "correct" << endl;
    else cout << "incorrect" << endl;

    return 0;
}
