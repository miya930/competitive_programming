#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<bool> ac(101000, false);
vector<int> wa(100100, 0);

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(m);
    vector<string> s(m);
    for (int i = 0; i < m; ++i) cin >> p[i] >> s[i], p[i]--;

    int ans_ac = 0, ans_wa = 0;
    for (int i = 0; i < m; ++i) {
        if (s[i] == "AC") {
            if (ac[p[i]] == false) {
                ac[p[i]] = true;
            }
        } else if (s[i] == "WA" && !ac[p[i]]) wa[p[i]]++;
    }

    for (int i = 0; i < n; ++i) {
        if (ac[i]) {
            ans_ac++;
            ans_wa += wa[i];
        }
    }

    cout << ans_ac << " " << ans_wa << endl;
}
