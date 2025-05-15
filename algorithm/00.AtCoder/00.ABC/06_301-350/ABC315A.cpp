#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    string str = "";
    string st = "aiueo";

    for (int i = 0; i < s.size(); i++) {
        bool ok = true;
        for (int j = 0; j < 5; j++) {
            if (s[i] == st[j]) ok = false;
        }
        if (ok) str.push_back(s[i]);
    }
    cout << str << endl;

    return 0;
}
