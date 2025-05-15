#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n = 8;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    string ver = "abcdefgh";
    string num = "87654321";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '*') {
                cout << ver[j] << num[i] << endl;
                return 0;
            }
        }
    }

    return 0;
}
