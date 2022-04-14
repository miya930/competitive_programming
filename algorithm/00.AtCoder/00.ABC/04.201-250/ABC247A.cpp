#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    string str;
    str.push_back('0');
    for (int i = 1; i < 4; ++i) str.push_back(s[i-1]);

    cout << str << endl;
    return 0;
}
