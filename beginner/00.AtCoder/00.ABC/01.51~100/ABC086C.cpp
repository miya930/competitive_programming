#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> x(N+1), y(N+1), t(N+1);
    for (int i = 1; i <= N; i++) cin >> t[i] >> x[i] >> y[i];
    t[0] = 0; x[0] = 0; y[0] = 0;

    for (int i = 1; i <= N; i++) {
        int dist = abs((x[i]-x[i-1])) + abs(y[i]-y[i-1]);
        int dt = t[i] - t[i-1];
        if ((dt < dist) || (dt%2 != dist%2)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
