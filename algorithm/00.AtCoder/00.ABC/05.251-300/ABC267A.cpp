#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    map<string, int> mp;
    mp["Monday"] = 5;
    mp["Tuesday"] = 4;
    mp["Wednesday"] = 3;
    mp["Thursday"] = 2;
    mp["Friday"] = 1;

    cout << mp[s] << endl;

    return 0;
}
