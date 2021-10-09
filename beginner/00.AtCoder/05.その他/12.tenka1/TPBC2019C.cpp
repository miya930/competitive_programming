// https://atcoder.jp/contests/tenka1-2019-beginner/tasks/tenka1_2019_c
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int INF = 1001001001;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> bsum(n+1, 0), wsum(n+1, 0);
    for (int i = 0; i < n; ++i) {
       if (s[i]=='#') bsum[i+1] = bsum[i] + 1;
       else bsum[i+1] = bsum[i];
    }

    for (int i = 0; i < n; ++i) {
        if (s[i]=='.') wsum[i+1] = wsum[i] + 1;
        else wsum[i+1] = wsum[i];
    }

    int ans = INF;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, bsum[i]+wsum[n]-wsum[i+1]);    
    }
    cout << ans << endl;
    return 0;
}
