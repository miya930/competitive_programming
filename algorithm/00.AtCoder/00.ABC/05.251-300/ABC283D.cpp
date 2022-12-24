#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    map<char, int> mp, empty;
    for (char i = 'a'; i <= 'z'; i++) empty[i] = 0;
    mp = empty;

    bool isok = true;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (mp[s[i]] >= 1) {
                isok = false;
                break;
            }

            mp[s[i]]++;
        } else if (s[i] == ')') {
            mp = empty;
        }
    }

    if (isok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
