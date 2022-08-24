#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int h1, w1;
    cin >> h1 >> w1;
    vector<vector<int>> a(h1, vector<int>(w1));
    for (int i = 0; i < h1; ++i) {
        for (int j = 0; j < w1; ++j) cin >> a[i][j];
    }
    int h2, w2;
    cin >> h2 >> w2;
    vector<vector<int>> b(h2, vector<int>(w2));
    for (int i = 0; i < h2; ++i) {
        for (int j = 0; j < w2; ++j) cin >> b[i][j];
    }

    for (int bit1 = 0; bit1 < (1<<h1); ++bit1) {
        for (int bit2 = 0; bit2 < (1<<w1); ++bit2) {
            vector<int> vec1, vec2;

            for (int i = 0; i < h1; ++i) {
                if ((bit1>>i) & 1) {
                    vec1.push_back(i);
                }
            }
            for (int i = 0; i < w1; ++i) {
                if ((bit2>>i) & 1) {
                    vec2.push_back(i);
                }
            }

            if (vec1.size() != h2 || vec2.size() != w2) continue;

            bool flg = true;
            for (int i = 0; i < vec1.size(); ++i) {
                for (int j = 0; j < vec2.size(); ++j) {
                    if (a[vec1[i]][vec2[j]] != b[i][j]) flg = false;
                }
            }

            if (flg) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
