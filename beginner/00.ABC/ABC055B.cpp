#include <iostream>
using namespace std;
const int mod = 1000000007;

int main(void)
{
    int N;
    cin >> N;

    long long power = 1;

    for (int i = 1; i <= N; i++) {
        power *= i;
        power %= mod;
    }

    cout << power << endl;
}
