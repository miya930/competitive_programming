#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int A[4];
    int i = 0;

    while(N>0) {
        A[i] = N%10;
        N /= 10;
        i++;
    }

    if (((A[0] == A[1]) && ( A[1] == A[2])) || ((A[1] == A[2]) && (A[2] == A[3])) || ((A[0] == A[1]) && (A[1] == A[2]) && (A[2] == A[3])))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
