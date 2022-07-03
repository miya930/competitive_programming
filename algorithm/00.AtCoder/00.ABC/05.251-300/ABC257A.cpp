#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, x;
    cin >> n >> x;

    string str = "";
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < n; ++j) {
            str += (char)('A' + i);
        }
    }

    cout << str[x-1] << endl;
}
