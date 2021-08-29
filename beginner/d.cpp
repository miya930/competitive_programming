#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int> > a(m);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int aa; cin >> aa;
            a[i].push_back(aa);
        }
    }

    bool ans = true;
    int cnt = 0;
    while (1) {
        bool done = false;
        for (int i = 0; i < m; ++i) {
            if (a[i].empty()) continue;
            int si1 = a[i].size() - 1;
            for (int j = i+1; j < m; ++j) {
                int si2 = a[j].size() - 1;
                if (a[i][si1] == a[j][si2]) {
                    a[i].pop_back();
                    a[j].pop_back();
                    done = true;
                    cnt += 2;
                }
            }
        }
        if (cnt == 2*n) {
            ans = true;
            break;
        }

        if (!done) {
            ans = false;
            break;
        }
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
