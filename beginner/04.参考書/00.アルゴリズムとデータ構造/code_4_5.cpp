#include <iostream>
using namespace std;

int fibo(int n)
{
    cout << "fibo(" << n << ")を呼び出しました" << endl;
    if (n == 0) return 1;
    else if (n == 1) return 1;

    int result = fibo(n-1) + fibo(n-2);
    return result;
}

int main(void)
{
    fibo(5);
}
