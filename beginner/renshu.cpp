#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t, c;
    cin >> t >> c;
    vector<int> table(t, 0), s(n), e(n);
    for (int i = 0; i < n; ++i) cin >> s[i] >> e[i];

    for (int i = 0; i < c; ++i) {
        table[s[i]]++;
        table[e[i]]++;
    }

    for (int i = 1; i < t; ++i) table[i] += table[i-1];
    // �ő�l�����߂�
    int m = 0;
    for (int i = 0; i < t; ++i) {
        m = max(m, table[i]);
    }
    cout << table[i] << endl;
}
