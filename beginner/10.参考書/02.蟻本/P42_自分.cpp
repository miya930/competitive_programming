#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> c(6), d(6);
    int a;
    for (int i = 0; i < 6; ++i) cin >> c[i];
    cin >> a;
    d[0] = 1; d[1] = 5; d[2] = 10; d[3] = 50; d[4] = 100; d[5] = 500;

    int ans = 0;
    for (int i = 5; i >= 0; --i) {
        while (1) {
            if (a-d[i]>=0 && c[i] > 0) {
                ans++;
                a -= d[i];
                c[i]--;
            } else {
                break;
            }
        }
    }
    cout << ans << endl;
}
