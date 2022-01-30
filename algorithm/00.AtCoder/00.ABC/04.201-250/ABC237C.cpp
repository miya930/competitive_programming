#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    int cnta = 0;
    int fira = 0;
    bool isa = true;
    for (int i = s.size()-1; i >= 0; i--) {
        if (isa == true && s[i] == 'a') cnta++;
        else {
            isa = false;
        }
    }
    isa = true;
    for (int i = 0; i < s.size()-1; ++i) {
        if (isa == true && s[i] == 'a') fira++;
        else isa = false;
    }

    if (fira > cnta) {
        cout << "No" << endl;
        return 0;
    }
    string str = s.substr(0, s.size()-(cnta-fira));

    bool ok = true;
    int n = str.size();
    for (int i = 0; i < n/2; ++i) {
        if (s[i] != s[n-i-1]) ok = false;
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
