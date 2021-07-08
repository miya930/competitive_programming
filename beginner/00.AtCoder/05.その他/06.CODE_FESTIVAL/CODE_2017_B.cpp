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

    map<char, int> mp;

    for (int i = 0; i < s.size(); ++i) mp[s[i]]++;

    int cnt_a = mp['a'];
    int cnt_b = mp['b'];
    int cnt_c = mp['c'];

    int diff = 0;
    for (int i = 0; i < 3; ++i) {
        diff = max(abs(cnt_a-cnt_b), abs(cnt_b-cnt_c));
        diff = max(diff, abs(cnt_a-cnt_c));
    }

    if ((diff >= 2) || (cnt_a==0 && s.size() > 2) || (cnt_b==0 && s.size() > 2) || (cnt_c==0 && s.size() > 2)) cout << "NO" << endl;
    else cout  << "YES" << endl;

    return 0;
}
