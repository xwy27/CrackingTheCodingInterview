#include "linkedList.hpp"

//move the data after middle node and delete the last node

void linkedList::removeMid(node* middle) {
    if (middle == NULL) return;
    int data = 0;
    while (middle->next != NULL) {
        middle->data = middle->next->data;
        middle = middle->next;
    }
    middle = NULL;
    remove(size-1, data);
}

int main() {
    linkedList test;
    int count, i, data;
    node* middle = new node(0);
    cout << "Size:";
    while ((cin >> count) && (count % 2 == 0)) {
        cout << "The size of list must be odd." << endl;
        cout << "Size:";
    }
    for (i = 0; i < count; i++) {
        cin >> data;
        if (i == count / 2) {
            middle->data = data;
            test.insert(i, middle);
        } else {
            test.insert(i, data);
        }
    }

    test.show();
    test.removeMid(middle);
    test.show();
}