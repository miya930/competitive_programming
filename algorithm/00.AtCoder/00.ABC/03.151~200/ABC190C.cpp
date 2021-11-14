#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(M), B(M);
    for (int i = 0; i < M; ++i) cin >> A[i] >> B[i];
    vector<int> A_cp(M), B_cp(M);
    
    int K;
    cin >> K;
    
    vector<int> C(K), D(K);
    for (int i = 0; i < K; ++i) cin >> C[i] >> D[i];

    int res = 0;

    for (int bits = 0; bits < (1 << K); bits++) {
        int sum = 0;
        A_cp = A;
        B_cp = B;
        for (int i = 0; i < K; ++i) {
            if(bits & (1<<i)) { 
                for (int j = 0; j < M; ++j) { 
                    if (A[j] == D[i]) A_cp[j] = 0;
                    else if (B[j] == D[i]) B_cp[j] = 0;
                }
            } else {
                for (int j = 0; j < M; ++j) {
                    if (A[j] == C[i]) A_cp[j] = 0;
                    else if (B[j] == C[i]) B_cp[j] = 0;
                }
            }
        }
        for (int k = 0; k < M; ++k) {
            if (A_cp[k]==0 && B_cp[k]==0)
                sum++;
        }
        res = max(res, sum);
    }
    cout << res << endl;
}
