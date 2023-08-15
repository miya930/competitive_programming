#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<pair<int,int>, int> mp;
int offset = 220000;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    
    bool flg = false;
    int cury = offset, curx = offset;
    for (int i = 0; i < n; i++) {
        if (mp.count(make_pair(cury, curx))) {
            flg = true;
            break;
        }

        mp[make_pair(cury, curx)]++;

        if (s[i] == 'R') {
            curx++;
        } else if (s[i] == 'L') {
            curx--;
        } else if (s[i] == 'U') {
            cury++;
        } else {
            cury--;
        }
    }

    if (mp.count(make_pair(cury, curx))) {
            flg = true;
    }
    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
