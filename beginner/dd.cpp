#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
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

    vector<vector<int> > vec(n+1);
    for (int i = 0; i < m; ++i) {
        for(int j = 0; j < (int)a[i].size()-1; ++j) {
            vec[a[i][j+1]].push_back(a[i][j]);
        }
    }


    map<int, int> mp;
    for (int i = 0; i < m; ++i) {
        int temp = a[i].size() - 1;
        mp[a[i][temp]]++;
    }

    bool ans = true;
    int cnt = 0;
    while (1) {
        bool ok = false;
        for (auto x : mp) {
            if (x.second == 2) {
                mp.erase(x.first);
                cnt += 2;
                for(int i = 0; i < vec[x.first].size(); ++i) {
                    mp[vec[x.first][i]]++;
                }
                ok = true;
                break;
            }
        }
        if (cnt == 2*n) {
            ans = true;
            break;
        }

        if (!ok) {
            ans = false;
            break;
        }
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
