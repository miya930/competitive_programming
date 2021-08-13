#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

bool check(int k, double val, vector<double> l) {
    double temp = 0;
    for (int i = 0; i < (int)l.size(); ++i) {
        temp += (double)l[i]/val;
    }
    if (k <= (int)temp) return true;
    else return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<double> l(n);
    double right = 0;
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
        right = max(right, l[i]);
    }

    double left = 0;
    while (right - left > 0.01) {
        double mid = (right + left) / 2;
        if (check(k, mid, l)) left = mid;
        else right = mid;
        cout << "right = " << right << endl;
    }

    right = (int)right;
    
    printf("%.2f\n", right);
}
