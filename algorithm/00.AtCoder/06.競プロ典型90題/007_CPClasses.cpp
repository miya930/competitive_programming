#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N, Q;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());

    cin >> Q;
    vector<int> B(Q);
    for (int i = 0; i < Q; i++) cin >> B[i];

    for (int i = 0; i < Q; ++i) {
        auto itr = lower_bound(A.begin(), A.end(), B[i]);
        int index = itr - A.begin();
        if (index == 0)                   cout << abs(A[index] - B[i]) << endl;
        else if (index > 0 && index < N)  cout << min(abs(A[index-1] - B[i]), abs(A[index] - B[i])) << endl;
        else if (index == N)              cout << B[i] - A[index - 1] << endl;
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int b;
        cin >> b;

        auto itr = upper_bound(a.begin(), a.end(), b) - a.begin();
        int tmp = a[itr] - b;
        if (itr != 0) {
            tmp = min(abs(tmp), abs(a[itr-1]-b));
        }

        if (itr == a.size()) cout << abs(a[a.size()-1]-b) << endl;
        else cout << tmp << endl;

    }

    return 0;
}
