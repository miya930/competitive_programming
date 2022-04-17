#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;
    vector<int> vec(10);
    int ans = 0;
    for (int i = 0; i < (int)s.size(); ++i) vec[(int)(s[i]-'0')]++;
    for (int i = 0; i < 10; ++i) {
        if (vec[i] == 0) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
