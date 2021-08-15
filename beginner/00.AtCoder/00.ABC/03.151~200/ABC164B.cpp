#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int cnt = 0;
    while (1) {
        if (cnt%2==0) c-=b;
        else a-=d;
        if (c <= 0) {
            cout << "Yes" << endl;
            break;
        } else if (a <= 0) {
            cout << "No" << endl;
            break;
        }
        cnt++;
    }
    return 0;
}
