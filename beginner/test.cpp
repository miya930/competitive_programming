#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 100, m = 2;
    auto f = [](int a, int b) {
        return a + b;
    };

    int x = f(n, m);
    cout << x << endl;

    return 0;
}

