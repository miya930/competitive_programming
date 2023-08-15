#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int r, c;
    cin >> r >> c;

    vector<string> b(r);
    for (int i = 0; i < r; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (b[i][j] != '.' && b[i][j] != '#') {
                int num = b[i][j] - '0';
                b[i][j] = '.';
                for (int y = 0; y < r; y++) {
                    for (int x = 0; x < c; x++) {
                        int diff = abs(i - y) + abs(j - x);
                        if (diff <= num && b[y][x] == '#') b[y][x] = '.';
                    }
                }
            } 
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0;j < c; j++) {
            cout << b[i][j];
        }
        cout << endl;
    }

    return 0;
}
