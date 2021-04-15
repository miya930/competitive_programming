#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
    int N, x;
    cin >> N >> x;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    
    int cnt = 0; //喜ぶ子供の人数をカウント

    sort(a.begin(), a.end()); // 喜ぶ子供の人数を最大化するために少ない子供から配る

    for (int i = 0; i < N; i++) {
        x -= a[i];
        if (x < 0)
            break;
        cnt++;
    }
    
    if(x > 0)
        cnt--; //余った分は余分に誰かにあげないといけないため

    cout << cnt << endl;
}
