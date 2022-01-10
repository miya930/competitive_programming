// 8^20 ‚Å long long Œ^‚Åó‚¯æ‚ê‚È‚¢ ~‚“
#include <iostream>
#include <vector>
using namespace std;

long long tot(long long n, int a) {
    long long res = 0;
    long long tmp = 1;
    while(n>0) {
        res += (n%10)*tmp;
        n /= 10;
        tmp *= a;
    }
    return res;
}

long long tto(long long n, long long a) {
    long long res = 0;
    long long tmp = 1;
    while (n > a-1) {
        long long c = n%a;
        if (c == 8) c = 5;
        res += c*tmp;
        n /= a;
        tmp *= 10;
    }
    if (n == 8) n = 5;
    res += n*tmp;
    return res;
}

int main()
{
    long long n;
    int k;
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        n = tto(tot(n, 8), 9);
    }
    cout << n << endl;
    return 0;
}
