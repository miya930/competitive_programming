#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s,t;
    cin >> s >> t;

    bool ok = false;
    if (s.size() < t.size()) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < s.size() - t.size() + 1; ++i) {
        string str = s.substr(i, t.size());

        if (str == t) {
            ok = true;
        }
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
