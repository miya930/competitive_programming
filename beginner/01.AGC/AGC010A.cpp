#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 1)
            cnt++;
    }

    if (cnt % 2 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
