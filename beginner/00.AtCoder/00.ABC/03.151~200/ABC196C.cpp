#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main(void)
{
    ll N;
    cin >> N;

    for (ll i = 1; ; ++i) {
        if(stoll(to_string(i)+to_string(i)) < N) {
            cout << i - 1 << endl;
            return 0;
        }
    }
}
