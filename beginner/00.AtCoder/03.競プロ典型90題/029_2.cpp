#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, w;
    cin >> w >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        l[i]--;
    }
    vector<int> compression;
    for (int i = 0; i < n; ++i) {
        compression.push_back(l[i]);
        compression.push_back(r[i]);
    }
    sort(compression.begin(), compression.end());
    compression.erase(unique(compression.begin(), compression.end()), compression.end());
    for (int i = 0; i < n; ++i) {
        l[i] = lower_bound(compression.begin(), compression.end(), l[i]) - compression.begin();
        r[i] = lower_bound(compression.begin(), compression.end(), r[i]) - compression.begin();
    }
    vector<int> h(compression.size() - 1);
    for (int i = 0; i < n; ++i) {
        int height = *max_element(h.begin() + l[i], h.begin() + r[i]) + 1;
        fill(h.begin() + l[i], h.begin() + r[i], height);
        cout << height << endl;
    }
}
