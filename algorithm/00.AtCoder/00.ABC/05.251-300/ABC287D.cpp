#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s, t;
    cin >> s >> t;

    int n = t.size();
    int m = s.size();
    vector<bool> left(n+1, false), right(n+1, false);
    for (int i = 0; i < n; i++) {
        if (s[i]=='?'||t[i]=='?'||s[i]==t[i]) {
            if (i == 0 || ((i > 0) && (left[i-1] == true))) {
                left[i] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[m-1-i] == '?' || t[n-1-i] == '?' || (s[m-1-i] == t[n-1-i])) {
            if (i == 0 || ((i > 0) && (right[i-1] == true))) {
                right[i] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            if(right[n-1]) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else if (i == n) {
            if(left[n-1]) cout << "Yes" << endl;
            else cout << "No" << endl; 
        } else {
            if (left[i] && right[n - 1 - i]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }

    }

    return 0;
}
