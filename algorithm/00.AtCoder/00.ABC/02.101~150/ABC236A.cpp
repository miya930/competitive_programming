#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    int a, b;
    cin >> a >> b;
    a--; b--;

    swap(s[a], s[b]);
    cout << s << endl;

    return 0;
}
