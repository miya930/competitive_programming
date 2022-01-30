#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == 'R') cnt++;
        else cnt = 0;
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}
