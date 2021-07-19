#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<vector<int> > g(t, vector<int>(t));
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            cin >> g[i][j];
        }
    }
    
}
