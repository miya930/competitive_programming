#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int l, r;
    cin >> l >> r;
    string s = "atcoder";
    string str = s.substr(l-1, r-l+1);

    cout << str << endl;

    return 0;
}
