#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N;
    vector<string> s(N);
    for (int i = 0; i < N; ++i) cin >> s[i];

    cin >> M;
    vector<string> t(M);
    for (int i = 0; i < M; ++i) cin >> t[i];

    map<string , int> mp;
    for (int i = 0; i < N; ++i) mp[s[i]]++;
    for (int i = 0; i < M; ++i) mp[t[i]]--;

    int ans = -1000000;
    for (auto x: mp) {
        ans = max(ans, x.second);
    }
    cout << ans << endl;
}
