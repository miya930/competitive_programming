#include <iostream>
#include <algorithm>
using namespace std;
int ans[2010];
const int inf = 1000000007;

void chmin(int &a, int b) {
    if (a > b) a = b;
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    x--;y--;

    for (int i = 0; i < n ;++i) {
        for (int j = i+1; j < n; ++j) {
            int k = inf;

            chmin(k, j-i);
            chmin(k, abs(x-i) + abs(y-j) + 1);

            ans[k]++;
        }
    }
    for (int i = 1; i < n; ++i) {
        cout << ans[i] << endl;
    }
}