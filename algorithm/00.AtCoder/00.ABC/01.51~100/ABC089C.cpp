#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);
    vector<ll> d(5, 0);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        if (s[i][0] == 'M') d[0]++;
        else if (s[i][0] == 'A') d[1]++;
        else if (s[i][0] == 'R') d[2]++;
        else if (s[i][0] == 'C') d[3]++;
        else if (s[i][0] == 'H') d[4]++;
    }

    ll ans = 0;

    for (int i = 0; i < 5; ++i) {
        for (int j = i+1; j < 5; ++j) {
            for (int k = j+1; k < 5; ++k) {
                ans += d[i]*d[j]*d[k];
            }
        }
    }
    cout << ans << endl;

}
