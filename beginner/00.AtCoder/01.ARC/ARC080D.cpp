#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int i = 0, j = 0, k = 0;
    int cnt = 0;
    vector<vector<int> > c(h, vector<int>(w, 0));
    while (cnt < h*w) {
        for (int l = 0; l < a[k]; ++l) {
            c[i][j] = k+1;
            cnt++;
            if (((i%2==0)&&(j==w-1)) || ((i%2==1) && (j==0))) {
                i++; continue;
            }
            if (i%2==0) j++;
            else j--;
        }
        k++;
    }
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}