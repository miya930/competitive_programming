#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            ans = i + 1;
            break;
        }
    } 
    cout << ans << endl;
    return 0;
}
