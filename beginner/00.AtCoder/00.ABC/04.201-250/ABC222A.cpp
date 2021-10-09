/**
   created: 09.10.2021 20:45:10
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    for (int i = n; i < 4; ++i) {
        s = '0' + s;
    }

    cout << s << endl;


    return 0;
}
