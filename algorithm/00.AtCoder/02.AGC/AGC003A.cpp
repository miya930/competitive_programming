#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    vector<int> dx(2, 0), dy(2, 0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'N') dx[0] = 1;
        else if (s[i] == 'S') dx[1] = 1;
        else if (s[i] == 'E') dy[0] = 1;
        else if (s[i] == 'W') dy[1] = 1;
    }

    if (dx[0]+dx[1] == 1 || dy[0]+dy[1] == 1) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
