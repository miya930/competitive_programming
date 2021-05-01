#include <iostream>
using namespace std;
typedef long long ll;
ll N;

void func(ll num, int check, ll& cnt)
{
    if (num > N) return;
    if (check == 0b111) cnt++;

    func(num*10+7, check | 0b001, cnt);
    func(num*10+5, check | 0b010, cnt);
    func(num*10+3, check | 0b100, cnt);
}

int main(void)
{
    cin >> N;
    ll cnt = 0;
    func(0, 0b000, cnt);

    cout << cnt << endl;
    return 0;
}
