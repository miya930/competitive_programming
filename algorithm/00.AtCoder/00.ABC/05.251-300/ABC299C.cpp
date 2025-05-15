#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    
    int ans = -1;
    int tmp = 0;
    bool iscount = false;
    for (int i = 0; i < n; i++) {
        if (i < n-1 && s[i] == '-' && s[i+1] == 'o') {
            iscount = true;
        } else if (i < n-1 && s[i] == 'o' && s[i+1] == '-') {
            iscount = false;
            tmp++;
            ans = max(ans, tmp);
            tmp = 0;
        } else if (iscount && s[i] == 'o') {
            tmp++;
            ans = max(ans, tmp);
        }
    }

    tmp = 0;
    for (int i = n-1; i >= 0; i--) {
        if (i > 0 && s[i] == '-' && s[i-1] == 'o') {
            iscount = true;
        } else if (i > 0 && s[i] == 'o' && s[i-1] == '-') {
            iscount = false;
            tmp++;
            ans = max(ans, tmp);
            tmp = 0;
        }else if (iscount && s[i] == 'o') {
            tmp++;
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;
    return 0;
}
