#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    int A[100100];
    for (int i = 0; i < N; i++) cin >> A[i];

    int cnt = 0;
    int flag_inc = false;
    int flag_dec = false;

    for (int i = 1; i < N; i++) {
        if ((flag_inc == false) && (flag_dec == false) ) {
            if (A[i-1] < A[i]) {
                cnt++;
                flag_inc = true;     
            } else if (A[i-1] > A[i]) {
                cnt++;
                flag_dec = true;
            }
        }

        if (((flag_inc == false) && (flag_dec == true)) || ((flag_inc == true) && (flag_dec == false))) {
            if ((flag_inc == true) && (A[i-1] > A[i])) {
                cnt++;
                flag_inc = false;
                flag_dec = true;
            } else if ((flag_dec == true) && (A[i-1] < A[i])){
                cnt++;
                flag_inc = true;
                flag_dec = false;
            }
        }
    }
    cout << cnt << endl;
}
