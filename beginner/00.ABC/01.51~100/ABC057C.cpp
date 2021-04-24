#include <iostream>
using namespace std;

// �����v�Z
long long Digit(long long N) {
    long long DigitN = 0;
    while(N > 0){
        DigitN++;
        N /= 10;
    }
    return DigitN;
}

// �����̑傫���ق���Ԃ�
long long Digit_Bigger(long long A, long long B) {
    if (Digit(A) < Digit(B))
        return Digit(B);
    else
        return Digit(A);
}

int main(void)
{
    long long N;
    cin >> N;

    long long min_Digit = 10000;

    // 10^10�̑S�T��������K�v�͂Ȃ��B�����10^5�𒴂�����
    for (long long i = 1; i < 100000; i++) {
        if ((N%i) == 0) {
            if (min_Digit > Digit_Bigger(i, N/i))
                min_Digit = Digit_Bigger(i, N/i);
        }
    }
    cout << min_Digit << endl;
}
