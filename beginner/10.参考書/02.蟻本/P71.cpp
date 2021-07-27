#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int heap[MAX_N], x = 0;

void push(int x) {
    int i = x++;

    while (i > 0) {
        int p = (i-1) / 2;

        if (heap[p] <= x) break;

        heap[i] = heap[p];
        i = p;
    }
    heap[i] = x;
}

void pop() {
    int ret = heap[0];

    int x = heap.back();
    int i = 0;

    while (i*2+1 < sz) {
        // Žq“¯Žm‚ð”äŠr
        int a = i*2 + 1, b = i*2 + 2;
        if (b < sz && heap[a] < heap[b]) swap(a, b);

        if (x <= heap[a]) break;

        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;

    return ret;
}
