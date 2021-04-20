// ÉÅÉÇÅF1000çÄÇ‹Ç≈ë´ÇµÇΩòaÇÕ500500
#include <iostream>
using namespace std;

int main(void)
{
    int A, B;
    cin >> A >> B;

    const long long E_max = 1000000;
    const long long E_min = -1000000;

    long long E[3000];
    long long sum_A = 0;
    long long sum_B = 0;

    for (long long i = 0; i < A; i++) {
        if (i < A - 1)
            E[i] = i + 1;     // äeçÄÇÃëçòaÇ™E_maxÇ∆Ç»ÇÈÇÊÇ§Ç…
        sum_A += E[i];
        if (i == (A - 1))
            E[i] = E_max - sum_A;
    }

    for (long long i = A; i < B+A; i++) {
        if (i < A + B -1)
            E[i] = - (i - A + 1);
        sum_B += E[i];
        if (i == (A+B-1))
            E[i] = E_min - sum_B;
    }

    for (int i = 0; i < A+B; i++)
        cout << E[i] << " ";
    
    cout << endl;
}
