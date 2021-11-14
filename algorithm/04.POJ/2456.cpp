#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000007;

bool check(int m, int mid, vector<int> x) {
    int temp = 1;
    int prev = 0;
    for (int i = 1; i < (int)x.size(); ++i) {
        if (x[i] - x[prev] >= mid) {
            temp++;
            prev = i;
        }
    }
    if (temp >= m) return true;
    else return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n), dist(n);
    for (int i = 0; i < n; ++i) cin >> x[i];

    sort(x.begin(), x.end());

    int right = INF;
    int left = 0;

    while(right - left > 1) {
        int mid = (right + left) / 2;
        if (check(m, mid, x)) left = mid;
        else right = mid;
    }
    
    cout << left << endl;
}
