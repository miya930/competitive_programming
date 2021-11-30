#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    int cnt = 0;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
            if (a[i][j]%2 == 1) cnt++; 
        }
    }

    vector<pair<int,int>> bef, af;
    bool move = false;
    for (int i = 0; i < h; ++i) {
        if (i%2 == 0) {
            for (int j = 0; j < w; ++j) {
                if (move == false) {
                    if (a[i][j]%2==1) {
                        if (cnt == 0 || cnt ==1) break;
                        move = true;
                        bef.push_back(make_pair(i, j));
                    }
                } else {
                    if (a[i][j]%2 == 1) {
                        move = false;
                        cnt -= 2;
                    } else {
                        bef.push_back(make_pair(i, j));
                    }
                    af.push_back(make_pair(i, j));
                }
            }
        } else {
            for (int j = w-1; j >= 0; --j) {
                if (move == false) {
                    if (a[i][j]%2==1) {
                        if (cnt == 0 || cnt ==1) break;
                        move = true;
                        bef.push_back(make_pair(i, j));
                    }
                } else {
                    if (a[i][j]%2 == 1) {
                        move = false;
                        cnt -= 2;
                    } else {
                        bef.push_back(make_pair(i, j));
                    }
                    af.push_back(make_pair(i, j));
                }
            }        
        
        }
    }

    cout << bef.size() << endl;
    for (int i = 0; i < bef.size(); ++i) {
        cout << bef[i].first+1 << " " << bef[i].second+1 << " " << af[i].first+1 << " " << af[i].second+1 << endl;
    }

    return 0;
}
