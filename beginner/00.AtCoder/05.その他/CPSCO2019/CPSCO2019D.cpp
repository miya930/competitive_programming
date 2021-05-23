#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isOK(vector<int> a,int n, int mid, int key) {
    int now = 1, count = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i-1]) now++;
        else now = 1;
        if (now > mid) {
            count++;
            now = 1;
            i++;
        }
    }
    if (count <= key) return true;
    else return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int right = n;
    int left = 0;
    while (right - left > 1) {
        int mid = left + (right - left)/2;
        if (isOK(a, n, mid, k)) right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}
