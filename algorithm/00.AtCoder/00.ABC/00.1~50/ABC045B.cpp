#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    vector<string> s(3);
    for (int i = 0; i < 3; ++i) cin >> s[i];
    for (int i = 0; i < 3; ++i) reverse(s[i].begin(), s[i].end());

    int idx = 0, ans = 0;
    while(1) {
        string cur = s[idx];
        if (cur.size() == 0) {
            ans = idx;
            break;
        }

        s[idx].erase(s[idx].end()-1);
        int last = cur.size() - 1;
        
        if (cur[last] == 'a') idx = 0;
        else if (cur[last] == 'b') idx = 1;
        else idx = 2;
    }

    if (ans == 0) cout << "A" << endl;
    else if (ans == 1) cout << "B" << endl;
    else cout << "C" << endl;

    return 0;
}
