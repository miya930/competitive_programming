#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<long long, long long> mp;

long long keta(long long n, long long& dig) {
    long long mod, sum = 0;
    while (n > 0) {
        dig++;
        mod = n % 10;
        sum += mod;
        mp[mod % 3]++;
        n /= 10;
    }
    return sum;
}

int main()
{
    long long n;
    cin >> n;

    long long dig = 0;
    long long sum = keta(n, dig);

    if (sum % 3 == 0) {
        cout << 0 << endl;
        return 0;
    } else if (sum % 3 == 2) {
        if (mp[2] >= 1 && dig >= 2) {
            cout << 1 << endl;
            return 0;
        } else if (mp[1] >= 2 && dig >= 3) {
            cout << 2 << endl;
            return 0;
        }
    } else if (sum % 3 == 1) {
        if (mp[1] >= 1 && dig >= 2) {
            cout << 1 << endl;
            return 0;
        }
        else if (mp[2] >= 2 && dig >= 3) {
            cout << 2 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
