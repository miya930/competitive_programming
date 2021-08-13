#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int ans = 0;
    int temp = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') {
            temp++;
        } else {
            ans = max(ans, temp);
            temp = 0;
        }

        if (i == (int)s.size() - 1) ans = max(ans, temp);
    }
    cout << ans << endl;
}
