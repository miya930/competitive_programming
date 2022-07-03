#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    string hor1 = "", hor2 = "";
    vector<string> ans;
    int tmp = 0;
    bool flg = true;
    for (int i = 0; i < n*b; ++i) {
        tmp++;
        if (flg) {
            hor1 += '.';
            hor2 += '#';
        } else {
            hor1 += '#';
            hor2 += '.';
        }
        if (tmp == b) {
            if (flg) flg = false;
            else flg = true;
            tmp = 0;
        }
    }

    tmp = 0;
    flg = true;
    for (int i = 0; i < n*a; ++i) {
        tmp++;
        if (flg) {
            ans.push_back(hor1);
        } else {
            ans.push_back(hor2);
        }
        if (tmp == a) {
            if (flg) flg = false;
            else flg = true;
            tmp = 0;
        }
    }

    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;

    return 0;
}
