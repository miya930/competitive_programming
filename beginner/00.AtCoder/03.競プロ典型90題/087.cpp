#include <iostream>
#include <vector>
using namespace std;
long long n, p, k;
long long a[60][60], dp[60][60];

long long count(long long x) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == -1) dp[i][j] = x;
            else dp[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < n; ++i) dp[i][i] = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    long long cnts = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            if (dp[i][j] <= p) cnts++;
        }
    }
    return cnts;
}

bool isOK(long long key, long long cm) {
	if (count(cm) <= key) return true;
	else return false;
}

long long get_border(long long key) {
    long long cl = 0, cr = 50000000000LL;
    while (cr - cl > 1) {
        long long cm = (cl + cr) / 2LL;
        if (isOK(key, cm)) cr = cm;
        else cl = cm;
    }
    return cr;
}


int main()
{
    cin >> n >> p >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    long long l = get_border(k);
    long long r = get_border(k-1);

    if (r-l > 2000000000LL) cout << "Infinity" << endl;
    else cout << r - l << endl;
}
