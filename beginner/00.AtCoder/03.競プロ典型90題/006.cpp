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
