#include <iostream>
#include <vector>
using namespace std;

int func(int n) {
    cout << "func(" << n << ")‚ðŒÄ‚Ño‚µ‚Ü‚µ‚½" << endl;

    if (n == 0)
        return n;
    
    int result = n + func(n-1);
    cout << n << "‚Ü‚Å‚Ì˜a = " << result << endl;

    return result;
}

int main(void)
{
    func(5);
    return 0;
}
