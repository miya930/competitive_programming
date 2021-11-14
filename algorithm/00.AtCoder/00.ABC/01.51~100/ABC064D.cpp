#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int now = 0;
    string ans = s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == ')') now--;
        else {
            if (now < 0) now = 1;
            else now++;
        }
        if (now < 0) ans = '(' + ans; 
    }
    
    now = 0;
    for (int i = 0; i < (int)ans.size(); ++i) {
        if (ans[i] == ')') now--;
        else now++;
    }
    if (now > 0) {
        for (int i = 0; i < now; ++i) ans = ans + ')';
    }
    cout << ans << endl;
    return 0;
}
