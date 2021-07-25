#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string s,ss, t;
    cin >> s >> t;

    int a = 0, b = n-1;

    while (a<=b) {
        bool left = false;
        for (int i = 0; i + a <= b; ++i) {
            if (s[a+i] < s[b-i]) {
                left = true;
                break;
            } else if (s[a+1] > s[b-1]) {
                break;
            }
        }
        if (left) putchar[a++];
        else putchar[b--];
    }
    putchar("\n");
}
