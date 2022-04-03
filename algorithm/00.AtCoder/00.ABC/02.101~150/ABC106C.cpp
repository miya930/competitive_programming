#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    ll k;
    cin >> s >> k; 
    
    int n = s.size();
    int cnt = 0;
    string str = "";
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            str += '1';
            cnt++;
        } else {
            break;
        }
    }

    if (k <= (int)str.size()) cout << '1' << endl;
    else cout << s[cnt] << endl;

    return 0;
}
