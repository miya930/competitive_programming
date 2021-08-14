#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;

    if (n >= 0 && n <= 125) cout << 4 << endl;
    else if (n >= 126 && n <= 211) cout << 6 << endl;
    else cout << 8 << endl;
}
