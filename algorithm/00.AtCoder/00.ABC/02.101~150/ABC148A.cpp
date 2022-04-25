#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b;
    cin >> a >> b;
    map<int,int> mp;
    mp[a]++;mp[b]++;

    for (int i = 1; i <= 3; ++i) {
        if (mp[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
