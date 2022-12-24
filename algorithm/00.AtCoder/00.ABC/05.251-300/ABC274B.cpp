#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h ,w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    vector<int> x(w, 0);
    for (int j = 0; j < w; j++) {
        int tmp = 0;
        for (int i = 0; i < h; i++) {
            if (s[i][j] == '#') tmp++;
        }
        x[j] = tmp;
    }

    for (int j = 0; j < w; j++) cout << x[j] << " ";
    cout << endl;

    return 0;
}
