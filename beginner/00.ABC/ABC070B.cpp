#include <iostream>
using namespace std;

int main(void)
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if (B >= C && B <= D && A < C ) {
        cout << B - C << endl;
    } else if (A >= C && B <= D ) {
        cout << B - A << endl;
    } else if (A >= C && A <= D & D < B) {
        cout << D - A << endl;
    } else if (C >= A && D <= B) {
        cout << D - C << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
