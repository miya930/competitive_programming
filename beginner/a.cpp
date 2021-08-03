#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int p;
        cin >> p;

        map<int, int> mp;
        for (int i = 2; i < 100100; ++i) {
            if (mp[p%i] == 0) {
                mp[p%i] = i;
            } else {
                cout << mp[p%i] << " " << i << endl;
                break;
            }
        }
    }
    return 0;
}