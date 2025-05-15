#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    map<string, int> mp;
    mp["ACE"]++;
    mp["BDF"]++;
    mp["CEG"]++;
    mp["DFA"]++;
    mp["EGB"]++;
    mp["FAC"]++;
    mp["GBD"]++;

    if (mp.count(s)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
