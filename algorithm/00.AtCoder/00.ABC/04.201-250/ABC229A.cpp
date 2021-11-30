#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    vector<string> s(2);
    for (int i = 0; i < 2; ++i) cin >> s[i];
    
    int cnt = 0;

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (s[i][j] == '#') cnt++;
        }
    }

    if (cnt == 2 && ((s[0][0] == '#' && s[1][1] == '#') || (s[1][0] == '#' && s[0][1] == '#') )) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
