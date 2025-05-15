#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'o') x++;
        else x--;
        if (x < 0) x = 0;
    }

    cout << x << endl;

    return 0;
}
