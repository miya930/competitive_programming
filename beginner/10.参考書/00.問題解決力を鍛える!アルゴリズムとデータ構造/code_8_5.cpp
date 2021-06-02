#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    string name;

    Node(string name_ = "") : next(NULL), prev(NULL), name(name_) { }
};

Node* nil;

void init(void) {
    nil = new Node();
    nil->next = nil;
    nil->prev = nil;
}

void printlist() {
    Node* cur = nil->next;
    for (; cur != nil; cur = cur->next) {
        cout << cur->name << " => ";
    }
    cout << endl;
}

void insert(Node* v, Node* p = nil) {
    v->next = p->next;
    v->prev = p;
    p->next->prev = v;
    p->next = v;
}

void erase(Node* v) {
    if (v == nil) return;
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v;
}

int main() {
    init();

    vector<string> names = { "yamamoto",
                            "watabane",
                            "ito",
                            "takahashi",
                            "suzuki",
                            "sato" };

    Node *watanabe = NULL;
    for (int i = 0; i < (int)names.size(); ++i) {
        Node* node = new Node(names[i]);
        insert(node);

        if (names[i] == "watanabe") watanabe = node;
    }

    cout << "before : " << endl;
    printlist();
    erase(watanabe);
    cout << "after : " << endl;
    printlist();
}
