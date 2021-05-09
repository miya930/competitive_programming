#include <iostream>
using namespace std;

int main(void)
{
    int H, W;
    cin >> H >> W;

    if (H==1) {
        cout << W << endl;
        return 0;
    } else if (W == 1) {
        cout << H << endl;
        return 0;
    }

    int hh = (H+1)/2;
    int ww = (W+1)/2;

    cout << hh*ww << endl;
}
