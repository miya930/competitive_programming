#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > d(n, vector<int>(2));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> d[i][j];
        }
    }

    int cnt = 0;
    bool flg = false;
    for (int i = 0; i < n; ++i) {
        if (d[i][0] == d[i][1]) {
            flg = true;
            cnt++;
        } else {
            flg = false;
            cnt = 0;
        }
        if (flg && cnt == 3) {
            cout << "Yes" << endl;
            return 0;
        }

    }
    cout << "No" << endl;
    return 0;
}
