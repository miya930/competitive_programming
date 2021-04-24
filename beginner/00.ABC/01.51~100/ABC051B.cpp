#include <iostream>
using namespace std;

int main(void)
{
    int K, S;
    cin >> K >> S;

    int cnt = 0;

    for (int i = 0; i <= K;i++) {
        for (int j = 0; j <= K;j++) {
            if ((S-i-j >= 0) && (S-i-j <= K))
                cnt++;
        }
    }

    cout << cnt << endl;
}
