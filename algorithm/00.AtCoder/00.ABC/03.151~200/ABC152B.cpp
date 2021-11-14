#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;

    if (a <= b) {
        for (int i = 0; i < b; i++) {
            cout << a;
            if (i == b -1)
                cout << endl;
        }       
    } else if (a > b) {
        for (int i = 0; i < a; i++) {
            cout << b;
            if (i == a - 1)
                cout << endl;
        }   
    }

    return 0;
}
