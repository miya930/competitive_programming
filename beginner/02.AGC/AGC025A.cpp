#include <iostream>
#include <algorithm>
using namespace std;

int SumOfDigit(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(void)
{
    int N;
    int Digit_min = 10000000;
    cin >> N;

    for (int i = 1; i < N; i++) {
        int Digit_sum = SumOfDigit(i) + SumOfDigit(N-i);
        Digit_min = min(Digit_min, Digit_sum);
    }

    cout << Digit_min << endl;
}
