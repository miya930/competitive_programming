#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    double a;
    cin >> a;
    int x = a * 10;
    int y = x%10;
    x = x / 10;

    if (y>=0 && y <= 2) cout << x << "-" << endl;
    else if (y >= 3 && y <= 6) cout << x << endl;
    else if (y >= 7 && y <= 9) cout << x << "+" << endl;
}
