#include <iostream>
using namespace std;

int main(void)
{
    int N;
    cin >> N;

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if (N == i*j) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}
