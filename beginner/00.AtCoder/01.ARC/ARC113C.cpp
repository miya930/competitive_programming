#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main()
{
    string s;
    cin >> s;

    long long ans = 0;
    map<char, int> mp;
    for (int i = s.size()-1; i >= 1; --i) {
        mp[s[i]]++;
        if (s[i] == s[i-1]) {
            int cnt = 0;
            for (int j = 'a'; j <= 'z'; j++) {
                if (j != s[i]) {
                    cnt += mp[j];
                    mp[j] = 0;
                }
            }
            ans += cnt;
            mp[s[i]] += cnt;
        }  
    }
    cout << ans << endl;
}
