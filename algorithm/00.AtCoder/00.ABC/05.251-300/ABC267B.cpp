#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    bool flg = false;
    
    vector<int> row(7, 0);
    if (s[6] == '1') row[0] = 1;
    if (s[3] == '1') row[1] = 1;
    if (s[7] == '1' || s[1] == '1') row[2] = 1;
    if (s[4] == '1') row[3] = 1;
    if (s[8] == '1' || s[2] == '1') row[4] = 1;
    if (s[5] == '1') row[5] = 1;
    if (s[9] == '1') row[6] = 1;

    for (int i = 0; i < (int)row.size()-2; ++i) {
        if (row[i] == 0) continue;
        if (row[i+1] == 1) continue;

        for (int j = i+2; j < (int)row.size(); ++j) {
            if (row[j] == 1) {
                flg = true;
                break;
            }
        }

        if (flg == true) break;
    }

    if (s[0] == '1') flg = false;

    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
