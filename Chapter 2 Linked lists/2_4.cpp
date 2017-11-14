#include "linkedList.hpp"

void linkedList::addList(linkedList &list, linkedList &result) {
    node* cur1 = head;
    node* cur2 = list.head;
    int addCount = list.Size(), count = Size();
    int i, carry = 0;
    for (i = 0; i < count; i++) {
        if (i < addCount) {
            int temp = cur1->data+cur2->data+carry;
            if (temp >= 10) {
                result.insert(i, temp%10);
                carry = 1;
            } else {
                result.insert(i, temp);
                carry = 0;
            }
            cur2 = cur2->next;
        } else {
            result.insert(i, cur1->data);
        }
        cur1 = cur1->next;
    }
}

int main() {
    linkedList add1, add2, result;
    int n1, n2, count1 = 0, count2 = 0;
    cin >> n1 >> n2;
    while (n1 > 0) {
        add1.insert(count1++, n1%10);
        n1 = n1 / 10;
    }
    while (n2 > 0) {
        add2.insert(count2++, n2%10);
        n2 = n2 / 10;
    }

    add1.show();
    add2.show();
    if (add1.Size() > add2.Size()) {
        add1.addList(add2, result);
    } else {
        add2.addList(add1, result);
    }
    result.show();
} 