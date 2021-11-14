#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int ans = 0;
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i-1]) ans++;
    }
    
    cout << ans << endl;

    return 0;
}
