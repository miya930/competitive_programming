#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
using ll = long long;

map<int, string> mp;

int main()
{
    string x;
    int n;
    cin >> x >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    vector<pair<string, int> > pa(n);
    for (int i = 0; i < n; ++i) {
        string t = "";
        for (int j = 0; j < s[i].size(); ++j) {
            for (int k = 0; k < 26; ++k) {
                if (s[i][j] == x[k]) {
                    t.push_back("abcdefghijklmnopqrstuvwxyz"[k]);
                    break;
                }
            }
        }
        pa[i] = make_pair(t, i);
    }

    sort(pa.begin(), pa.end());

    for (int i = 0; i < n; ++i) {
        mp[i] = s[pa[i].second];
    }

    for (int i = 0; i < n; ++i) {
        cout << mp[i] << endl;
    }
    return 0;

}
