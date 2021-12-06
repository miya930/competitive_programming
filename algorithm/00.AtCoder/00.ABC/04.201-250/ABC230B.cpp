#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    bool flag = false;
    string t = "";
    
    while (t.size() < s.size()+10) t = t + "oxx";
    
    for (int i = 0; i < (int)t.size() - n; ++i) {
        if (t.substr(i, n) == s) flag = true; 
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
