/**
   created: 09.10.2021 20:47:45
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int m;
    cin >> m;
    vector<string> s(m);
    for (int i = 0; i < m; ++i) cin >> s[i];

    for (int i = 0; i < m; ++i) {
        string res = "";
        for (int j = (int)s[i].size()-1; j >= 0; --j) {
            if (s[i][j] == 'A') res.push_back('T');
            else if (s[i][j] == 'T') res.push_back('A');
            else if (s[i][j] == 'C') res.push_back('G');
            else res.push_back('C');
        }
        cout << res << endl;
    }

    return 0;
}
