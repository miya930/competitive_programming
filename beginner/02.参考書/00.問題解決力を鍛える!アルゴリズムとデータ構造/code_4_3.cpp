#include <iostream>
#include <vector>
using namespace std;

int func(int n) {
    cout << "func(" << n << ")���Ăяo���܂���" << endl;

    if (n == 0)
        return n;
    
    int result = n + func(n-1);
    cout << n << "�܂ł̘a = " << result << endl;

    return result;
}

int main(void)
{
    func(5);
    return 0;
}
