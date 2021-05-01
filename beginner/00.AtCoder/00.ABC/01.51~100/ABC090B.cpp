#include <iostream>
#include <string>
using namespace std;

bool IsKaibun(int n) {
    int N[5] = {0};
    for (int i = 0; i < 5; i++) {
        N[i] = n % 10;
        n /= 10;
    }
    if ((N[0] == N[4]) && (N[1] == N[3]))
        return true;
    else
        return false;
}

int main(void)
{
    int A, B;
    int cnt = 0;
    cin >> A >> B;

    for (int i = A; i <= B; i++) {
        if(IsKaibun(i))
            cnt++;
    }

    cout << cnt << endl;
}
