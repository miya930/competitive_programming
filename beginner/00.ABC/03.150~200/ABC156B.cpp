#include <iostream>
using namespace std;

int main(void) {
    long long N, K;
    int Digit = 0;
    cin >> N >> K;

    while(N > 0) {
        N /= K;
        Digit++;
    }
    
    cout << Digit << endl;
}
