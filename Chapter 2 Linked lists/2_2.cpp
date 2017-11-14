#include "linkedList.hpp"

int linkedList::nthToLast(int n) {
    if (n > size || n < 0)   return -1;
    node* first = head;
    node* second = head;
    int count = 0;
    while (first != NULL) {
        first = first->next;
        if (count >= n+1) {
            second = second->next;
        }
        ++count;
    }
    return second->data;
}

int main() {
    linkedList test;
    int count, data;
    cin >> count;
    for (int i = 0; i < count; ++i) {
        cin >> data;
        test.insert(i, data);
    }

    test.show();

    for (int i = 0; i < count; i++) {
        cout << (i == 0 ? "NULL <- " : "")
             << test.nthToLast(i)
             << (i == count - 1 ? "" : " <- ");
    }
    cout << endl;
    cout << test.nthToLast(7);
}