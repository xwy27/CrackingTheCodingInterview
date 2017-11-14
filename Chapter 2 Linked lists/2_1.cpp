#include "linkedList.hpp"

void linkedList::removeDup() {
    if (head == NULL)   return;
    bool arr[256] = {0};
    node* pre = head;
    node* cur = head->next;
    node* temp = NULL;
    arr[head->data] = true;
    while (cur != NULL) {
        if (!arr[cur->data]) {
            arr[cur->data] = true;
            pre = cur;
            cur = cur->next;
        } else {
            temp = cur;
            pre->next = cur->next;
            cur = cur->next;
            delete temp;
            temp = NULL;
        }
    }
}

int main() {
    linkedList list;
    int n, data;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> data;
        list.insert(i, data);
    }
    list.show();
    list.removeDup();
    list.show();
}

/* Follow up
    Without temporary buffer, using the method with O(n^2) complexity

    void linkedList::removeDup() {
        if (head == NULL)   return;
        node* temp = head;
        node* hold = NULL;
        node* pre = NULL;
        node* cur = NULL;
        while (temp != NULL) {
            pre = temp;
            cur = temp->next;
            while (cur != NULL) {
                if (temp->data == cur->data) {
                    pre->next = cur->next;
                    hold = cur;
                    cur = cur->next;
                    delete hold;
                    hold = NULL;
                } else {
                    pre = cur;
                    cur = cur->next;
                }
            }
            temp = temp->next;
        }
    }
 */