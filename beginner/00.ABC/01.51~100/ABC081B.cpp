#include <iostream>
#include <vector>
using namespace std;

int count_dev(int n) {
    int count = 0;
    while(n>0) {
        if (n%2==0) count++;
        else break;
        n /= 2;
    }

    return count;
}

int main(void)
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    int min_value = 100000000;
    for (int i = 0; i < N; i++) {
        if(min_value > count_dev(A[i]))
            min_value = count_dev(A[i]);
    }

    cout << min_value << endl;
}
