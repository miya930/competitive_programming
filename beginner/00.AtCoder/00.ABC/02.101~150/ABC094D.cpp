#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    int ai = a[n-1];
    int aj = a[0];
    for (int i = 0; i < n-1; ++i) {
        if (abs(a[i] - ai/2) <= abs(aj - ai/2)) aj = a[i];
    }
    cout << ai << " " << aj << endl;
    return 0;
}
