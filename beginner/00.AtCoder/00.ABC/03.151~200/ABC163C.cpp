#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> b(n, 0);
    for (int i = 0; i < n-1; ++i) {
        int a; cin >> a;
        b[a-1]++;
    }

    for (int i = 0; i < n; ++i) cout << b[i] << endl;
    return 0;

}
