#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int A[120],B[120];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];

    int max_A = 0;
    int min_B = 1000000000;
    for (int i = 0; i < N; i++) {
        max_A = max(max_A, A[i]);
        min_B = min(min_B, B[i]);
    }

    if (max_A > min_B)
        cout << 0 << endl;
    else if (max_A == min_B)
        cout << 1 << endl;
    else
        cout << min_B - max_A + 1 << endl;

}
