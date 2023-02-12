#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
string s;
vector<int> dir;

int calc(int k) {
    int res = 0;
    vector<int> f(n+100);

    int sum = 0;
    for (int i = 0; i + k <= n; i++) {
        if ((dir[i]+sum)%2 == 1) {
            res++;
            f[i] = 1;
        }
        sum += f[i];

        if (i - k + 1 >= 0) {
            sum -= f[i-k+1];
        }
    }

    for (int i = n - k + 1; i < n; i++) {
        if ((dir[i]+sum)%2 != 0) {
            return -1;
        }
        if (i -k + 1 >= 0) {
            sum -= f[i-k+1];
        }
    }

    return res;

}

int main()
{
    cin >> n >> s;

    dir.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'F') dir[i] = 0;
        else dir[i] = 1;
    }

    int ansk = 1, m = n;
    for (int k = 1; k <= n; k++) {
        int tmp = calc(k);
        if (tmp != -1 && m > tmp) {
            ansk = k;
            m = tmp;
        }
    }

    cout << ansk << " " << m << endl;

    return 0;
}
