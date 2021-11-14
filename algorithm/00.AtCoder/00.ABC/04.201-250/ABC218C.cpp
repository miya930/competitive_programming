#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

bool offset[600][600];

vector<string> rotate(vector<string> s, int n) {
    vector<string> res = s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] = s[n-j-1][i];
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    int cnts = 0, cntt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '#') cnts++;
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        for (int j = 0; j < n; ++j) {
            if (t[i][j] == '#') cntt++;    
        }
    }

    if (cnts != cntt) {
        cout << "No" << endl;
        return 0;
    }

    bool first = false;
    int x, y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s[i][j] == '#' && first == false) {
                first = true;
                x = i;
                y = j;
            } else if (s[i][j] == '#' && first == true) {
                offset[300+i-x][300+j-y] = true;
            }
        }
    }

    vector<string> str = t;
    for (int rot = 0; rot < 4; ++rot) {
        str = rotate(str, n);
        bool first = false;
        bool ok = true;

        /*cout << "rot = " << rot << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) cout << str[i][j];
            cout << endl;
        }*/

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (str[i][j] == '#') {
                    if (first == false) {
                        first = true;
                        x = i;
                        y = j;
                    } else {
                        if (!offset[300+i-x][300+j-y]) ok = false;
                    }
                }
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    return 0;

}
