#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    string ans = "";
    for (int i = 0; i < n; i++) {
        if (i != n-1 && s[i]=='n' && s[i+1] =='a') {
            ans += "nya";
            i++;
        } else {
            ans.push_back(s[i]);
        }
    }
    cout << ans << endl;
    return 0;
}
