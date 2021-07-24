#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;

    string t = "000";

    for (char i = '0'; i <= '9'; ++i) {
        t[0] = i;
        for (char j = '0'; j <= '9'; ++j) {
            t[1] = j;
            for (char k = '0'; k <= '9'; ++k) {
                t[2] = k;
                vector<int> b(3, 0);
                int l = 0;
                for (int m = 0; m < 3; m++) {
                    while (l < n) {
                        if (t[m] == s[l]) {
                            b[m] = l;
                            l++;
                            break;
                        }
                        l++;
                    }
                }
                if (b[0] < b[1] && b[1] < b[2]) ans++;
            }
        }
    }
    cout << ans << endl;
}
