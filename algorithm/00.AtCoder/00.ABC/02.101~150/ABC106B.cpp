#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int cnt = 0;
    int ans = 0;

    for (int i = 1;i <= N; i+=2) {
        cnt = 0;
        for (int j = 1; j <= i; j++) {
            if (i%j==0)
                cnt++;
        }
        if (cnt == 8)
            ans++;
    }

    cout << ans << endl;

}
