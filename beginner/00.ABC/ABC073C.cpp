#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000100;

int main(void)
{
    long long N;
    cin >> N;

    vector<int> A(N+1);
    vector<bool> Num(MAX, false);
    vector<bool> Num_flag(MAX, false);
    for (int i = 1; i <= N; i++) cin >> A[i];

    for (int i = 1; i < N+1; i++) {
        if (Num[A[i]] == false)
            Num[A[i]] = true;
        else
            Num[A[i]] = false;
    }

    long long cnt = 0;

    for (int i = 1; i < N+1; i++) {
        if ((Num[A[i]] == true) && (Num_flag[A[i]] == false))
            cnt++;
            Num_flag[A[i]] = true;
    }

    cout << cnt << endl;
}
