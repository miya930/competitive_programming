#include <iostream>
using namespace std;

int GCD(int m, int n)
{
    if (n == 0) return m;

    return GCD(n, m%n);
}

int main(void)
{
    cout << GCD(51, 15) << endl;
    cout << GCD(15, 6) << endl;
}
