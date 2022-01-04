#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    map<string,int> mp;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        mp[s]++;
    } 

    string ans = "";
    int ma = 0;
    for (auto x : mp) {
        if (ma < x.second) {
            ans = x.first;
            ma = x.second;
        }
    }

    cout << ans << endl;

    return 0;
}
