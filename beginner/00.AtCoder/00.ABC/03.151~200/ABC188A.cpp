#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    if (x < y) swap(x, y);

    if (x - y < 3) cout << "Yes" << endl;
    else cout << "No" << endl;
}
