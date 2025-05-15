#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n = 8;
    vector<int> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    bool ok = true;
    for (int i = 0; i < n-1; i++) {
        if (s[i] > s[i+1]) ok = false;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] < 100 || 675 < s[i]) ok = false;
        if (s[i] % 25 != 0) ok = false;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
