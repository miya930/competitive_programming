#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n/2;++i) {
        if (s[i] != s[n-i-1]) ans++;
    }
    cout << ans << endl;
}
