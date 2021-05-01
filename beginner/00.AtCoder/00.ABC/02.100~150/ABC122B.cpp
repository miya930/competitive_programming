#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    string S;
    cin >> S;

    int cnt = 0;
    int ans = 0;

    for (unsigned int i = 0; i < S.length();i++) {
        if((S[i] == 'A') || (S[i] == 'C') || (S[i] == 'G') || (S[i] == 'T')) {
            cnt++;
            ans = max(ans, cnt);
        } else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    cout << ans << endl;

}
