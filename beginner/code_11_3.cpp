#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {
    vector<int> par, siz;

    // ‰Šú‰»
    UnionFind(int n) : par(n, -1), siz(n, 1) { }

    // ª‚ğ‹‚ß‚é
    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]); 
    }

    // x ‚Æ y ‚ª“¯‚¶ƒOƒ‹[ƒv‚É‘®‚·‚é‚©‚Ç‚¤‚© (ª‚ªˆê’v‚·‚é‚©‚Ç‚¤‚©)
    
}

int main()
{

}
