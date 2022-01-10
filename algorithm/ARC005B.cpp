#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int x, y;
    string W;
    cin >> x >> y >> W;
    map<string, int> mp;
    x--; y--;

    vector<string> vec(9);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> vec[i][j];
        }
    }

    mp["L"] = 1; mp["R"] = 2; mp["U"] = 3; mp["D"] = 4;
    mp["RU"] = 5; mp["RD"] = 6; mp["LU"] = 7; mp["LD"] = 8;

    vector<int> ans(4);
    cout << vec[y][x] << endl;
    for (int i = 0; i < 4; ++i) {
        switch(mp[W]) {
            case 1:
                ans[i] = vec[y][x];
                if (x == 0) W = "R";
                else x--;                
                break;
            case 2:
                ans[i] = vec[y][x];
                if (x == 8) W = "L";
                else x++;
                break;
            case 3:
                ans[i] = vec[y][x];
                if (y == 0) W = "D";
                else y--;               
                break;
            case 4:
                ans[i] = vec[y][x];
                if (y == 8) W = "U";
                else y++;
                break;
            case 5:
                ans[i] = vec[y][x];                
                if (x == 8 && y == 0) W = "LD";
                else if (x == 8) W = "LU";
                else if (y == 0) W = "RD";
                else {
                    x++;
                    y--;
                }
                break;
            case 6:
                ans[i] = vec[y][x];            
                if (x == 8 && y == 8) W = "LU";
                else if (x == 8) W = "LD";
                else if (y == 8) W = "RU";
                else {
                    x++;
                    y++;
                }
                break;
            case 7:
                ans[i] = vec[y][x];            
                if (x == 0 && y == 0) W = "RD";
                else if (x == 0) W = "RU";
                else if (y == 0) W = "LD";
                else {
                    x--;
                    y--;
                }
                break;
            case 8:
                ans[i] = vec[y][x];            
                if (x == 0 && y == 8) W = "RU";
                else if (x == 0) W = "RD";
                else if (y == 8) W = "LU";
                else {
                    x--;
                    y++;
                }
                break;
        }
    }

    for (int i = 0; i < 4; ++i) cout << ans[i];
    cout << endl;
    return 0;
}
