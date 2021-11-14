#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int c;
    cin >> c;
    vector<int> x(4);
    for (int i = 0; i < 4;++i) {
        x[i] = c%10;
        c /= 10;
    }
    reverse(x.begin(), x.end());

    bool flg = true;
    if (x[0] == x[1] && x[1] == x[2] && x[2] == x[3]) {
        cout << "Weak" << endl;
        return 0;
    } else {
        for (int i = 1; i < 4; ++i) {
            if (x[i] != (x[i-1]+1)%10) {
                cout << "Strong" << endl;
                return 0;
            }
        }
    }
    cout << "Weak" << endl;
    return 0;
}
