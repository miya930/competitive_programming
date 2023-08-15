#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<string> w(n);
    for (int i = 0;i < n; i++) cin >> w[i];

    bool flg = false;
    for (int i = 0; i < n; i++) {
        if (w[i] == "and" || w[i] == "not" || w[i] == "that" || w[i] == "the" || w[i] == "you") flg = true;
    }

    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
