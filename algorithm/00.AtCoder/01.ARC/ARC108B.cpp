/**
   created: 23.10.2021 18:12:30
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    string s, t;
    cin >> n >> s;

    for (int i = 0; i < n; ++i){
        t.push_back(s[i]);
        int m = t.size();
        if (m >= 3) {
            if (t[m-1] == 'x' && t[m-2] == 'o' && t[m-3] == 'f') {
                t = t.substr(0, m-3);
            }
        }
    }

    cout << t.size() << endl;

    return 0;
}
