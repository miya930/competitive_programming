#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    bool ok = false;
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n-i; ++j) {
            for (int k = j; k <= n; ++k) {
                string tmp = s.substr(i,j);
                tmp += s.substr(k, n-k);
                if (tmp == "keyence") ok = true;
            }
        }
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
