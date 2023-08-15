#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int k;
    string s;
    cin >> k >> s;

    int n = s.size();
    if (n <= k) cout << s << endl;
    else {
        string str = s.substr(0, k);
        str += "...";
        cout << str << endl;
    }

    return 0;
}
