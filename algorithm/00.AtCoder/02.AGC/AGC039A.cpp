#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;

    long long ans = 0;
    string cp = s;
    bool flg = true;
    for (int i = 1; i < (int)s.size(); ++i) {
        if (s[i] != s[i-1]) flg = false;
    }
    
    if (flg) {
        cout << (long long)s.size() * k / 2 << endl;
        return 0;
    }

    for (int i = 1; i < (int)s.size(); ++i) {
        if (cp[i] == cp[i-1]) {
            ans += k;
            cp[i] = 'A';
        }
    }

    int a = 1, b = 1;
    for (int i = 0; i < (int)s.size()-1; ++i) {
        if(s[i] == s[i+1]) a++;
        else break;
    }
    for (int i = (int)s.size()-1; i > 0; --i) {
        if (s[i] == s[i-1]) b++;
        else break;
    }
 
    if (s[0] == s[s.size()-1]) ans += (k-1)*((a+b)/2 - a/2 - b/2);
    
    cout << ans << endl;
}
