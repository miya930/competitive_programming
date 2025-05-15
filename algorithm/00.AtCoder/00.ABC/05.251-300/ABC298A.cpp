#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    bool isok = false;
    bool isng = false;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') isok = true;
        else if (s[i] == 'x') isng = true;
    }

    if (isok && !isng) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
