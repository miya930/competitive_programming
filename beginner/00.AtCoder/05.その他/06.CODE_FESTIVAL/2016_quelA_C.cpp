#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    string s;
    int k;
    cin >> s >> k;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'a') continue;
        int n = 26 - (s[i] - 'a');
        if (n <= k) {
            k -= n;
            s[i] = 'a';
        }
    }    

    s[s.size()-1] = (char)((s[s.size()-1]+(k%26)-'a')%26+'a');

    cout << s << endl;

    return 0;
}
