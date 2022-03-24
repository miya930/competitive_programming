#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int nex[100009][26];

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    for (int i = 0; i < 26; ++i) nex[s.size()][i] = s.size();
    for (int i = (int)s.size() - 1; i >= 0; i--) {
        for (int j = 0; j < 26; ++j) {
            if ((int)(s[i]-'a') == j) {
                nex[i][j] = i;
            } else {
                nex[i][j] = nex[i+1][j];
            }
        }
    }

    string answer = "";
    int CurrentPos = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < 26; ++j) {
            int NexPos = nex[CurrentPos][j];
            int MaxPossibleLength = (int)(s.size() - NexPos - 1) + i;
            if (MaxPossibleLength >= k) {
                answer += (char)('a'+j);
                CurrentPos = NexPos + 1;
                break;
            }
        }
    }

    cout << answer << endl;
}





#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    vector<vector<int>> c(n+1, vector<int>(26, n));
    for (int i = n-1; i >= 0; --i) {
        int tmp = s[i] - 'a';
        for (int j = 0; j < 26; ++j) {
            if (tmp == j) c[i][j] = i;
            else c[i][j] = c[i+1][j];
        }
    }

    string ans = "";
    int curpos = 0;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < 26; ++j) {
            int nexpos = c[curpos][j];
            int maxpossiblelen = (int)(s.size() - nexpos-1) + i;
            if (maxpossiblelen >= k) {
                ans += (char)('a' + j);
                curpos = nexpos + 1;
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
