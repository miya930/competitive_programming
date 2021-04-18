/*** map‚Å’PŒê‚Æ‰ñ”‚ğ•R‚Ã‚¯‚ÄŠi”[‚·‚é ***/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int main(void)
{
    int N, M;
    cin >> N;

    int ans = 0;

    vector<string> s(N);
    for (int i = 0; i < N; i++) cin >> s[i];

    cin >> M;
    vector<string> t(M);
    for (int i = 0; i < M; i++) cin >> t[i];

    for (int i = 0; i < N; i++) {
        int score = 0;
        for (int j = 0; j < N; j++) {
            if(s[i] == s[j]) score++;}
        for (int j = 0; j < M; j++) {
            if(s[i] == t[j]) score--;}
        ans = max(ans, score);
    }
    cout << ans << endl;
}
