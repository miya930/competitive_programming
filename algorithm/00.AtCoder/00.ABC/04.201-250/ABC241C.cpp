#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            bool flag = false;
            int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;

            if (x < n-5) {
                for (int i = 0; i < 6; ++i) if (s[x+i][y] == '#') cnt1++;
            }
            if (y < n-5) {
                for (int i = 0; i < 6; ++i) if (s[x][y+i] == '#') cnt2++;
            }
            if (x < n-5 && y < n-5) {
                for (int i = 0; i < 6; ++i) if (s[x+i][y+i] == '#') cnt3++;
            }
            if (x < n-5 && y >= 5) {
                for (int i = 0; i < 6; ++i) if (s[x+i][y-i] == '#') cnt4++;
            }

            if (cnt1 >= 4 || cnt2 >= 4 || cnt3 >= 4 || cnt4 >= 4) flag = true;
            if (flag) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
