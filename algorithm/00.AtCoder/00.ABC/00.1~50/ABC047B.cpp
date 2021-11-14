#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int W, H, N;
    cin >> W >> H >> N;

    vector<int> x(N), y(N), a(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> a[i];
    }

    int x_min = 0;
    int y_min = 0;
    int x_max = W;
    int y_max = H;

    for (int i = 0; i < N; i++) {
        if (a[i] == 1) {
            x_min = max(x_min, x[i]);
        } else if (a[i] == 2) {
            x_max = min(x_max, x[i]);
        } else if (a[i] == 3) {
            y_min = max(y_min, y[i]);
        } else {
            y_max = min(y_max, y[i]);
        }        
    }

    int area = (x_max - x_min) * (y_max - y_min);       
    
    if ((x_max - x_min) >= 0 && (y_max - y_min) >= 0)    // メモ：area > 0 とすると(x_max - x_min) < 0 && (y_max - y_min) < 0もプラスになってしまう。 
        cout << area << endl;
    else
        cout << 0 << endl;
}

