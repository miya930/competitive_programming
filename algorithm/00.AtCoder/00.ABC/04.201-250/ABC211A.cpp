#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;

    double ans = (double)(a-b)/3.0 + b;
    printf("%.10f\n", ans);
}
