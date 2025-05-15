#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    map<string, int> mp;
    for (int i = 0; i < n; i++) {
        mp[s[i]]++;
    }

    cout << "AC" << " x " << mp["AC"] << endl;
    cout << "WA" << " x " << mp["WA"] << endl;
    cout << "TLE" << " x " << mp["TLE"] << endl;
    cout << "RE" << " x " << mp["RE"] << endl;

    return 0;
}
