#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n = 9;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    map<int,pair<int,int>> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mp[cnt++] = make_pair(i, j);
        }
    }

    int ans = 0;
    for (int i = 0; i < mp.size(); i++) {
        for (int j = i+1; j < mp.size(); j++) {
            for (int k = j+1; k < mp.size(); k++) {
                for (int l = k+1; l < mp.size(); l++) {
                    int x1 = mp[i].first;
                    int y1 = mp[i].second;
                    int x2 = mp[j].first;
                    int y2 = mp[j].second;
                    int x3 = mp[k].first;
                    int y3 = mp[k].second;
                    int x4 = mp[l].first;
                    int y4 = mp[l].second;

                    if ((s[x1][y1] != '#') || (s[x2][y2] != '#') || (s[x3][y3] != '#') || (s[x4][y4] != '#')) continue;

                    vector<int> vec;

                    vec.push_back((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
                    vec.push_back((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
                    vec.push_back((x1 - x4)*(x1 - x4) + (y1 - y4)*(y1 - y4));
                    vec.push_back((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));
                    vec.push_back((x2 - x4)*(x2 - x4) + (y2 - y4)*(y2 - y4));
                    vec.push_back((x3 - x4)*(x3 - x4) + (y3 - y4)*(y3 - y4));

                    sort (vec.begin(), vec.end());

                    if ((vec[0] != vec[1]) || (vec[0] != vec[2]) || (vec[0] != vec[3])) continue;
                    if ((vec[4] != vec[5]) || (vec[4] != 2*vec[0])) continue;

                    ans++;

                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
