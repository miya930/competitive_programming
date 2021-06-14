#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n;++i) cin >> h[i];

    int pre = h[n-1];
    for (int i = n-1; i > 0; --i) {
        if (h[i-1] - h[i] > 1) {
            cout << "No" << endl;
            return 0;
        } else if (h[i-1] - h[i] == 1) h[i-1]--;
    }
    cout << "Yes" << endl;
    return 0;
}
