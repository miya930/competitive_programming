#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    bool isng = false;
    for (int i = 0; i < n; i++) {
        bool isok = false;
        if (s[i] == t[i]) isok = true;
        if (((s[i] == '0') && (t[i] == 'o')) || ((s[i] == 'o') && (t[i] == '0'))) isok = true;
        if (((s[i] == 'l') && (t[i] == '1')) || ((s[i] == '1') && (t[i] == 'l'))) isok = true;

        if (!isok) {
            isng = true;
            break;
        }
    }

    if (isng) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
