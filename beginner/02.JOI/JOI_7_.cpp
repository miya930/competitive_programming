#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int m; cin >> m;
    vector<pair<int, int> > a(m);
    for (int i = 0; i < m; ++i) cin >> a[i].first >> a[i].second;

    int n; cin >> n;
    vector<pair<int, int> > b(n);
    for (int i = 0; i < n; ++i) cin >> b[i].first >> b[i].second;

    map<pair<int, int>, int> mp;

    for (int i = 0; i < n; ++i) mp[b[i]]++;

    for (int i = 0; i < n; ++i) {
        int of_x = b[i].first - a[0].first;
        int of_y = b[i].second - a[0].second;
        bool flag = true;

        for (int i = 0; i < m; ++i) {
            pair<int, int> temp;
            temp.first = a[i].first;
            temp.second = a[i].second;
            temp.first += of_x;
            temp.second += of_y;

            if (mp[temp] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << of_x << " " << of_y << endl;
            return 0;
        }
    }
    return 0;
}
