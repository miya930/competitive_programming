#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
const int INF = 1001001001;

int main()
{
    string s;
    cin >> s;

    map<char, int> mp;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) mp[s[i]]++;

    int ans = INF;
    for (auto x : mp) {
        int ma = 0;
        int temp = 0;
        for (int i = 0; i < n; ++i) {
            if (x.first == s[i]) {
                ma = max(temp, ma); 
                temp = 0;
            } else {
                temp++;
                if (i == n-1) ma = max(temp, ma);
            }
        }

        ans = min(ans, ma);
    }

    cout << ans << endl;
    return 0;

}
