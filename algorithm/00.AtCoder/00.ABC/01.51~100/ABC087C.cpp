#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int A[2][110];

    for (int i = 0;i < 2; i++) {
        for(int j = 0;j < N; j++) {
            cin >> A[i][j];
        }
    }

    int sum = 0;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        sum = 0;
        int down = i;
        for (int j = 0; j < down+1; j++) {
            sum += A[0][j];
        }
        sum += A[1][down];
        if (down != N-1) {
            for (int k = down+1; k < N; k++)
                sum += A[1][k];
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;
}
