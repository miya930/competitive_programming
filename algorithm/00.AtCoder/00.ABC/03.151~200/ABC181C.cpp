#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int> > pos(n);
    for (int i = 0; i < n; ++i) cin >> pos[i].first >> pos[i].second;

    map<pair<int, int>, int> mp;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int x1 = pos[i].first, y1 = pos[i].second;
                int x2 = pos[j].first, y2 = pos[j].second;
                int x3 = pos[k].first, y3 = pos[k].second;
                x1 -= x3;
                x2 -= x3;
                y1 -= y3;
                y2 -= y3;
                if (x1 * y2 == x2 * y1) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
