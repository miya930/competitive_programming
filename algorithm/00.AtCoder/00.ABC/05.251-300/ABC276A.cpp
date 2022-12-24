#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    int ans = -1;
    for (int i = s.size()-1; i >= 0; i--) {
        if (s[i] == 'a') {
            ans = i+1;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
