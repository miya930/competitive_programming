#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    string s; 
    cin >> s;

    string mas = s, mis = s;

    for (int i = 0; i < (int)s.size(); ++i) {
        char ss = s[0];
        for (int j = 0; j < (int)s.size()-1; ++j) {
            s[j] = s[j+1];
        }
        s[s.size()-1] = ss;
        if (mas <= s) mas = s;
        if (mis >= s) mis = s;
    }

    cout << mis << endl;
    cout << mas << endl;

    return 0;
}
