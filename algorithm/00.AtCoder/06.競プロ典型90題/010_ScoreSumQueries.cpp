#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N, Q;

    cin >> N;
    vector<int> c(N+1),p(N+1);
    for (int i = 1; i <= N; ++i) cin >> c[i] >> p[i];

    cin >> Q;
    vector<int> l(Q), r(Q);
    for (int i = 0; i < Q; ++i) cin >> l[i] >> r[i];

    // �ݐϘa
    vector<int> s_1(N+1), s_2(N+1);
    s_1[0] = 0; s_2[0] = 0;
    for (int i = 1; i <= N; i++) {
        if(c[i] == 1) {
            s_1[i] = s_1[i-1] + p[i];
            s_2[i] = s_2[i-1]; 
        } else {
            s_1[i] = s_1[i-1];
            s_2[i] = s_2[i-1] + p[i];
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << s_1[r[i]] - s_1[l[i]-1] << ' ' << s_2[r[i]] - s_2[l[i]-1] << endl;
    }
    return 0;
}

/*** 2022.3.13 復習 ***/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> c(n), p(n);
    for (int i = 0; i < n; ++i) cin >> c[i] >> p[i];

    vector<ll> sum1(n+1, 0), sum2(n+1, 0);
    for (int i = 0; i < n; ++i) {
        if (c[i] == 1) {
            sum1[i+1] = sum1[i] + p[i];
            sum2[i+1] = sum2[i];
        } else {
            sum2[i+1] = sum2[i] + p[i];
            sum1[i+1] = sum1[i];
        }
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        cout << sum1[r+1] - sum1[l] << " " << sum2[r+1] - sum2[l] << endl;
    }

    return 0;
}
