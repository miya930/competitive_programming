/**
   created: 22.10.2021 22:42:01
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    string s;
    cin >> s;

    map<char, int> mp;
    for (int i = 0; i < (int)s.size(); ++i) mp[s[i]]++;

    bool all = true;
    for (int i = 0; i < 26; ++i) {
        if (mp[i+'a'] == 0) all = false; 
    }

    bool change = false;
    if (all == false) {
        for (int i = 0; i < 26; ++i) {
            if (mp[i+'a'] == 0) {
                s = s + (char)(i+'a');
                change = true;
                break;
            }
        }
    } else {
        string str = "";
        for (int i = (int)s.size()-1; i >= 0; --i) {
            if (str == "") {
                mp[s[i]]--;
                str = str + s[i];
            } else {
                for (int j = 0; j < str.size(); ++j) {
                    if (s[i] < str[j]) {
                        s[i] = str[j];
                        change = true;
                        s = s.substr(0, i+1);
                        break;
                    }
                }

                if (change) break;
                else {
                    str = str + s[i];
                    sort(str.begin(), str.end());
                }
            }
        }
    }

    if (change) cout << s << endl;
    else cout << -1 << endl;

    return 0;
}
