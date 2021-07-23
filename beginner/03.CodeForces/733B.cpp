#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int H, W;
        cin >> H >> W;

        for (int h = 0; h < H; h++) {
            if (h == 0 || h == H-1) {
                for (int w = 0; w < W; ++w) {
                    if (w%2 == 0) cout << 1;
                    else cout << 0;
                }
            } else if (h==1 || h == H-2) {
                for (int w = 0; w < W; ++w) cout << 0;
            } else if (2 <= h && h < H-2) { 
                if (h%2==0) {
                    for (int w = 0; w < W; ++w) {
                        if (w==0 || w==W-1) cout << 1;
                        else cout << 0;
                    }
                } else {
                    for (int w = 0; w < W; ++w) cout << 0;
                }
            }
            cout << endl;
        }
    }
}
