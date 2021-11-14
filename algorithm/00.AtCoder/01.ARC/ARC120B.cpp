#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
const int MOD = 998244353;

int main(void){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) cin >> s[i];

    ll ans = 1;

    for (int l = 0; l < h+w-1; ++l) {
        map<char, int> cnt;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (i + j == l) cnt[s[i][j]]++;
            }
        }
        if (cnt.count('R') == 0 && cnt.count('B') == 0) {
            ans *= 2;
            ans %= MOD;
        } else if (cnt.count('R') != 0 && cnt.count('B') != 0)
            ans *= 0;
    }
    cout << ans << endl;
}
