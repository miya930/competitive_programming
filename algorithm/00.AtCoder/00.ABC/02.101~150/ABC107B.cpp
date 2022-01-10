#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) cin >> s[i];

    vector<bool> ver(h, false), hor(w, false);
    for (int i = 0; i < h; ++i) {
        bool exist = false;
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '#') exist = true; 
        }
        if (exist) ver[i] = true;
    }
    for (int j = 0; j < w; ++j) {
        bool exist = false;
        for (int i = 0; i < h; ++i) {
            if (s[i][j] == '#') exist = true;
        }
        if (exist) hor[j] = true;
    }

    for (int i = 0; i < h; ++i) {
        if (!ver[i]) continue;
        for (int j = 0; j < w; ++j) {
            if (hor[j] == true) cout << s[i][j];
        }
        cout << endl;
    }

    return 0;
}
