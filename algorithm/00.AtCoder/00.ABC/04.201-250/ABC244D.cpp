#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    vector<string> s(3), t(3);
    for (int i = 0; i < 3; ++i) cin >> s[i];
    for (int i = 0; i < 3; ++i) cin >> t[i];

    int cnt = 0;
    for (int i = 0; i < 3; ++i) {
        if (s[i] != t[i]) cnt++;
    }

    if (cnt == 0 || cnt == 3) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
