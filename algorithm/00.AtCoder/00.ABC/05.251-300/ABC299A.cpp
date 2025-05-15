#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    bool isstart = false;
    bool exist = false;
    bool isend = false;
    for (int i = 0; i < n; i++) {
        if (!isstart && s[i] == '|') {
            isstart = true;
        } else if (isstart && s[i] == '*') {
            exist = true;
        } else if (!isend && exist && s[i] == '|') {
            isend = true;
        }
    }
    if (isend) cout << "in" << endl;
    else cout << "out" << endl;

    return 0;
}
