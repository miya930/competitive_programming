#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    reverse(t.begin(), t.end());
    reverse(s.begin(), s.end());

    int cnt = 0;
    int index;
    bool ok = false;
    for (int i = 0 ; i < s.size(); ++i) {
        if ((s[i] == '?') || (t[cnt] == s[i])) cnt++;
        else cnt = 0;

        if (cnt == t.size()) {
            ok = true;
            index = i;
            break;
        }
    }

    if (!ok) {
        cout << "UNRESTORABLE" << endl;
        return 0;
    }

    for (int i = 0; i < t.size(); ++i) s[index-t.size()+i + 1] = t[i];
    
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '?') s[i] = 'a';
    }
    
    reverse(s.begin(), s.end());

    cout << s << endl;
}
