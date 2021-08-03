#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<vector<int> > field(n, vector<int>(n));
        for (int i = 0 ; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> field[i][j];
            }
        }

        
    }
    return 0;
}
