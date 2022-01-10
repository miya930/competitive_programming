#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    string a = "AKIHABARA";
    int tmp[] = {0, 4, 6, 8};
    int n = a.size();

    bool flag = false;
    for (int bits = 0; bits < (1<<4); ++bits) {
        string b = "";
        vector<int> rec;
        for (int i = 0; i < 4; ++i) {
            if ((bits>>i) & 1) rec.push_back(tmp[i]); 
        }

        for (int i = 0; i < n; ++i) {
            if (a[i] == 'A') {
                bool flag2 = false;
                for (int j = 0; j < rec.size(); ++j) {
                    if (rec[j] == i) flag2 = true;
                }
                if (flag2) continue;
                else b += a[i];
            } else {
                b += a[i];
            }
        }

        if (s == b) flag = true;
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
