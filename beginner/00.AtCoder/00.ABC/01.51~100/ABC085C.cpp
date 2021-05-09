#include <iostream>
using namespace std;

int main(void)
{
    int N, Y;
    cin >> N >> Y;

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N-i; ++j) {
            if (Y-10000*i-5000*j-1000*(N-i-j) == 0) {
                cout << i << ' ' << j << ' ' << N - i -j << endl;
                return 0;
            }
        }
    }
    cout << -1 << ' ' << -1 << ' ' << -1  << endl;
    return 0;
}
