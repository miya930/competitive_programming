#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 2000000000;

int main()
{
    int a, b, w;
    cin >> a >> b >> w;

    w *= 1000;
    int res_min = INF;
    int res_max = 0;

    for (int i = 0; i < w+1; ++i) {
        int l = i*a;
        int r = i*b;
        if (l <= w && r >= w) {
            res_min = min(res_min, i);
            res_max = max(res_max, i);
        }
    }
    if (res_min != INF)
        cout << res_min << ' ' << res_max << endl;
    else
        cout << "UNSATISFIABLE" << endl;
}

