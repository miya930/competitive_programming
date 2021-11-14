#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        int temp = n % 3;
        if (temp == 0) cout << n / 3 << " " << n / 3 << endl;
        else if (temp == 1) {
            cout << n / 3 + 1 << " " << n /3 << endl;
        } else {
            cout << n / 3 << " " << n / 3 + 1 << endl;
        }
    }
}
