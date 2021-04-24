#include <iostream>

using namespace std;

int main(void)
{
    long long N, A, B;
    cin >> N >> A >> B;

    long long sum_i = 0;
    long long sum = 0;

    for (long long i = 1; i <= N; ++i) {
        long long temp = i;
        sum_i = 0;

        while (1) {
            sum_i += temp % 10;
            temp /= 10;
            if (temp == 0)
                break;
        }
        if ((sum_i >= A) && (sum_i <= B))
            sum += i;
    }

    cout << sum << endl;
}
