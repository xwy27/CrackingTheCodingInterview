#include "linkedList.hpp"

/*  Algorithm 
1.Head is k nodes from LoopStart (by definition) 
2.MeetingPoint for n1 and n2 with different speed is k nodes from LoopStart

tips:Consider two nodes as different people running around a track 
 */

void linkedList::circular(int pos) {
    if (pos < 0 || pos >= size) return;
    node* cur = head;
    node* loop = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    while (pos > 0 && loop != NULL) {
        loop = loop->next;
        --pos;
    }

    cur->next = loop;
    cout << "Set start: " << loop->data << endl;
}

void linkedList::removeCir() {
    node* cur = head;
    int count = size-1;
    while (count > 0 && cur!= NULL) {
        cur = cur->next;
        --count;
    }
    cur->next = NULL;
}

node* linkedList::startOfLoop() {
    node* fast = head;
    node* slow = head;
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) {
            break;
        }
    }

    if (fast->next == NULL) {
        return NULL;
    }

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

int main () {
    linkedList test;
    int count, i, data, pos;
    cin >> count;
    for (i = 0; i < count; i++) {
        cin >> data;
        test.insert(i, data);
    }
    test.show();
    cout << "circular pos:";
    cin >> pos;
    test.circular(pos);
    cout << "Finded start: " << test.startOfLoop()->data << endl;
    test.removeCir();
    return 0;
}