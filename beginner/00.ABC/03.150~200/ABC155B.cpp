#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int cnt = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 0) {
            if ((A[i]%3!=0) && (A[i]%5!=0))
                cnt++;
        }
    }

    if (cnt)
        cout << "DENIED" << endl;
    else
        cout << "APPROVED" << endl;

}
