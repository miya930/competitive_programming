#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int s[1010][1010];

int main()
{
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    for (int i = 0; i < b; ++i) {
        for (int j = 0; j < a; ++j) s[i][j] = 0;
        for (int j = a; j < w; ++j) s[i][j] = 1;
    }
    for (int i = b; i < h; ++i) {
        for (int j = 0; j < a; ++j) s[i][j] = 1;
        for (int j = a; j < w; ++j) s[i][j] = 0;
    }

    bool ng = false;
    for (int i = 0; i < h; ++i) {
        int zero = 0, one = 0;
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == 0) zero++;
            else one++;
        }
        if (min(one, zero) != a) ng = true; 
    }

    for (int j = 0; j < w; ++j ){
        int zero = 0, one = 0;
        for (int i = 0; i < h; ++i) {
            if (s[i][j] == 0) zero++;
            else one++;
        }
        if (min(one, zero) != b) ng = true;
    }

    if (ng) cout << "No" << endl;
    else {
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cout << s[i][j];
            }
            cout << endl;
        }
    } 
    return 0;
}
