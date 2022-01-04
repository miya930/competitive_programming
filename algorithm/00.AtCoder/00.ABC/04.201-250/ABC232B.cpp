#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s, t;
    cin >> s >> t;

    bool ans = false;
    for (int i = 0; i <= 26; ++i) {
        string c = s;
        int sz = c.size();

        for (int  j= 0 ;j < sz; ++j) {
            c[j] = (c[j]-'a'+i)%26 + 'a';
        }

        if (c == t)  ans = true;       
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
