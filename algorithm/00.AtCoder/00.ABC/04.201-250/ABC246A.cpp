#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    map<int,int> mp1, mp2;
    mp1[x1]++; mp1[x2]++; mp1[x3]++;
    mp2[y1]++; mp2[y2]++; mp2[y3]++;

    int ansx, ansy;
    for (auto i : mp1){
        if (i.second == 1) ansx = i.first;
    }
    for (auto i : mp2) {
        if (i.second == 1) ansy = i.first;
    }

    cout << ansx << " " << ansy << endl;
    return 0;
}
