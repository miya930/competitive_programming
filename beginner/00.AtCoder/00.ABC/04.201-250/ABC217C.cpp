#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }

    vector<int> q(n);
    for (int i = 0; i < n; ++i) {
        q[p[i]] = i+1;
    }

    for (int i = 0; i < n; ++i) cout << q[i] << " ";
    cout << endl;
    return 0;
}
