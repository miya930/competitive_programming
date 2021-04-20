#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    const int lower = max(A, C);
    const int upper = min(B, D);

    cout << max(0, upper - lower) << endl;
}
