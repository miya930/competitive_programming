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
