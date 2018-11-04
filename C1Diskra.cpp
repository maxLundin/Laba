//
// Created by max on 02.11.2018.
//


#include <bits/stdc++.h>

using namespace std;

bool mas[4000][4000];


struct Node {
    Node *b;
    Node *f;
    int numb;
};

Node *finish = new Node();
Node *start = new Node();

string st;

void dosmth(Node *a, int pos) {
    cout << "1 " << a->b->numb << " " << pos << std::endl;
    cin >> st;
    if (st[0] == 'Y') {
        Node *no = new Node();
        no->f = a;
        no->b = a->b;
        no->numb = pos;
        no->b->f = no;
        no->f->b = no;
    } else if (a->b->numb == start->numb) {
        Node *no = new Node();
        no->numb = pos;
        no->f = start;
        no->b = nullptr;
        start->b = no;
        start = no;
    } else {
        dosmth(a->b, pos);
    }
}


int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    if (n == 1) {
        cout << "0 1";
        exit(0);
    }

    cout << "1 1 2" << std::endl;
    cin >> st;
    finish->b = start;
    start->f = finish;
    finish->f = nullptr;
    start->b = nullptr;
    if (st[0] == 'Y') {
        finish->numb = 2;
        start->numb = 1;
    } else {
        finish->numb = 1;
        start->numb = 2;
    }

    for (int i = 3; i <= n; i++) {
        cout << "1 " << finish->numb << " " << i << std::endl;
        cin >> st;
        if (st[0] == 'Y') {
            Node *a = new Node();
            a->numb = i;
            a->b = finish;
            finish->f = a;
            a->f = nullptr;
            finish = a;
        } else {
            dosmth(finish, i);
        }
    }
    Node *node = start;
    cout << "0 ";
    while (node != nullptr) {
        cout << node->numb << " ";
        node = node->f;
    }
}

