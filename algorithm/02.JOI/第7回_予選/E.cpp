#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int> > a(r, vector<int>(c));
    vector<int> vec(c);
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cin >> a[i][j];
        }
    }

    for (int j = 0; j < c; ++j) {
        int cnt = 0;
        for (int i = 0; i < r; ++i) {
            if (a[i][j] == 0) cnt++;
        }
        vec[j] = cnt;
    }

    int ans = 0;
    for (int bit = 0; bit < 1<<r; ++bit) {
        vector<int> temp, cp = vec;
        int sum = 0;
        for (int i = 0; i < r; ++i) {
            if (bit>>i & 1) temp.push_back(i);
        }

        for (int i = 0; i < temp.size(); ++i) {
            int v = temp[i];
            for (int j = 0; j < c; ++j) {
                if (a[v][j]) cp[j]++;
                else cp[j]--;
            }
        }

        for (int j = 0; j < c; ++j) {
            sum += max(cp[j], r-cp[j]);
        }
        
        ans = max(ans, sum);
    }    
    
    cout << ans << endl;
    return 0;
}
