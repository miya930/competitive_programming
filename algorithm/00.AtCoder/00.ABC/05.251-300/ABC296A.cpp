#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    bool isng = false;
    for (int i = 0; i < n-1; i++) {
        if ((s[i] == 'M') && (s[i+1] == 'M')) isng = true;
        else if ((s[i] == 'F') && (s[i+1] == 'F')) isng = true;
    }

    if (isng) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
