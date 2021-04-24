#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    long long N, Y;
    cin >> N >> Y;

    for (int i = 0; i <= N; i++) {               // 1000‰~ŽD‚Ì–‡”
        for (int j = 0; j <= N - i; j++) {       // 5000‰~ŽD‚Ì–‡”
            if ((Y - 1000*i - 5000*j) % 10000 == 0) {
                int x;
                x = (Y - 1000*i - 5000*j) / 10000;
                if ((x + i + j) == N) {
                    cout << x << " " << j << " " << i << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << " " << -1 << " " << -1 << endl;
}
