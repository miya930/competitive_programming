#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

void func(int val, int check, int &cnt)
{
    if (val > N) return;
    if (check == 0b111) cnt++;

    func(val*10+7, check | 0b001, cnt);
    func(val*10+5, check | 0b010, cnt);
    func(val*10+3, check | 0b100, cnt);
}

int main(void)
{
    int N;
    cin >> N;
    int cnt = 0;
    func(0, 0b100, cnt);

    cout << cnt << endl;
}
