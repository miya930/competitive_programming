#include <iostream>
using namespace std;

int main(void)
{
    int A, B, C;
    cin >> A >> B >> C;

    bool flag = false;

    for (int i = A; i <= A*B; i+=A) {
        if ((i%B) == C)
            flag = true;
    }

    if(flag) {
        cout << "YES" << endl;
        return 0;
    } else {
        cout << "NO" << endl;
        return 0;
    }
}
