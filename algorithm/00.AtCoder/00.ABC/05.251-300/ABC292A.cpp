#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        ans.push_back(s[i]+'A'-'a');
    }

    cout << ans << endl;
    return 0;
}
