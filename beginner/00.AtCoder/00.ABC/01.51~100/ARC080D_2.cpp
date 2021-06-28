#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int> > c(h, vector<int>(w));
    int now_h = 0, now_w = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < a[i]; ++j) {
            c[now_h][now_w] = i+1;
            now_w++;
            if (now_w == w) {
                now_h++;
                now_w = 0;
            }
        }
    }
    
    for (int i = 0; i < h; ++i) {
        if (i%2 == 0) continue;
        for (int j = 0; j < w/2; ++j) {
            swap(c[i][j], c[i][w-j-1]);
        }
    }
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}