#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s,t;
    cin >> s >> t;
    map<char, int> sm, tm;
    int sa = 0, ta = 0;
    string atcoder = "atcoder";
    for (int i = 0; i < t.size(); i++) {
        if (s[i] != '@') sm[s[i]]++;
        else sa++;

        if (t[i] != '@') tm[t[i]]++;
        else ta++;
    }

    bool ng = false;
    for (char c = 'a'; c <= 'z'; c++) {
        int nums = sm[c];
        int numt = tm[c];
        
        bool isin = false;
        for (int i = 0; i < atcoder.size(); i++) {
            if (c == atcoder[i]) {
                isin = true;
                break;
            }
        }

        if (nums != numt) {
            if (isin) {
                int ma = min(nums, numt);
                nums -= ma;
                numt -= ma;
                if (nums > 0) {
                    ta -= nums;
                } else {
                    sa -= numt;
                }

                if (ta < 0 || sa < 0) {
                    ng = true;
                    break;
                }

            } else {
                ng = true;
                break;
            }
        }
    }

    if (ng) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
