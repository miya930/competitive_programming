#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        int cnt = mp[s[i]];
        mp[s[i]]++;

        if (cnt == 0) cout << s[i] << endl;
        else {
            string str = to_string(cnt);
            cout << s[i] << '(' << str << ')' << endl;
        }
    }

    return 0;
}
