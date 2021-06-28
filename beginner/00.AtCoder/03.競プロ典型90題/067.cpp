#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long base8_to_long(string n) {
    long long res = 0, tmp = 1, m = n.size();
    for (int i = m-1; i >= 0; --i) {
        res += (n[i] - '0')*tmp;
        tmp *= 8LL;
    }
    return res;
}

string long_to_base9(long long n) {
    if (n == 0) return "0";
    string res = "";
    while (n > 0) {
        res = (char)((n%9) + '0') + res;
        n /= 9;
    }
    return res;
}

int main() {
    string n;
    int k;
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        n = long_to_base9(base8_to_long(n));
        for (int j = 0; j < n.size(); ++j) {
            if (n[j] == '8') n[j] = '5';
        }
    }
    cout << n << endl;
}
