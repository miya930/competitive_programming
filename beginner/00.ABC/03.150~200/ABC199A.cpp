#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    int A, B, C;
    cin >> A >> B >> C;

    if ((A*A+B*B)< C*C)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
