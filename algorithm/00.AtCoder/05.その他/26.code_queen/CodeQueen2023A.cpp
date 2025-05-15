#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    char c;
    cin >> s >> c;
    
    int idx = 0;
    while(idx < s.size()) {
        if (s[idx] == c) {
            s.insert(s.begin()+idx, c);
            idx += 2;
        } else {
            idx++;
        }
    }
    cout << s << endl;

    return 0;
}
