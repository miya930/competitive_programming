#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
const int MAX = 100010;

int main(void)
{
    int N;
    cin >> N;

    int t[MAX] = {0}, x[MAX] = {0}, y[MAX] = {0};
    for (int i = 1; i <= N; i++) cin >> t[i] >> x[i] >> y[i];

    for (int i = 1; i <= N; i++) {
        int dt = t[i] - t[i-1];
        int dxy = abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]); 
        if (((dt % 2) == (dxy % 2)) && (dt >= dxy)) {
            continue;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}
