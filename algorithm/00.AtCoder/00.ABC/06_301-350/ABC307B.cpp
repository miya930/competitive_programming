#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    bool exist = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            string str = s[i] + s[j];
            int m = str.size();
            bool ok = true;
            for (int k = 0; k < m/2; k++) {
                if (str[k] != str[m-k-1]) ok = false;
            }

            if (ok) exist = true;
        }
    }
    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
