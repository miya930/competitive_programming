#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int max_tri(in)

int main(void)
{
    int N;
    cin >> N;

    vector<int> A(N), B(N), C(N), D(N), E(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i] >> C[i] >> D[i] >> E[i];

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                int max_a; 
            }
        }
    }
    cout << ans << endl;
}
