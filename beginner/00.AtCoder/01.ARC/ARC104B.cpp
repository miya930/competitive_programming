#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n; cin >> n;
    string s; cin >> s;

    long long ans = 0;
    for (int left = 0; left < n; ++left) {
        long long cnt_a = 0, cnt_c = 0, cnt_t = 0, cnt_g = 0;
        for (int right = left; right < n; ++ right) {
            if (s[right] == 'A') cnt_a++;
            else if (s[right] == 'C')cnt_c++;
            else if (s[right] == 'T')cnt_t++;
            else cnt_g++;
            if (cnt_a == cnt_t && cnt_c == cnt_g) ans++;
        }
    }
    cout << ans << endl;
}
