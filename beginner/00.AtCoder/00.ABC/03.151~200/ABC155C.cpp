#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; ++i) cin >> s[i];

    map<string, int> mp;
    int max_cnt = 0;

    for (int i = 0; i < N; ++i) {
        mp[s[i]]++;
        max_cnt = max(max_cnt, mp[s[i]]);
    }
    for (auto x : mp) {
        if (x.second == max_cnt) cout << x.first << endl;
    }

    return 0;
}
