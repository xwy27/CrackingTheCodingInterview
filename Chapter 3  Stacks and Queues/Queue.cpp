#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "node.hpp"

using std::cin;
using std::cout;
using std::endl;

class Queue {
    private:
        node* first;
        node* back;
    public:
        Queue() {
            first = back = NULL;
        }

        ~Queue() {
            node* temp = first;
            while (temp != back) {
                first = first->next;
                delete temp;
                temp = first;
            }
            delete temp;
            temp = first = back = NULL;
        }

        bool empty() const {
            return first == NULL;
        }

        bool enQueue(int val) {
            if (first == NULL) {
                node* temp = new node(val);
                first = back = temp;
            } else {
                node* temp = new node(val);
                back->next = temp;
                back = temp;
            }
            return true;
        }

        int deQueue() {
            if (first == NULL)  return -1;
            node* temp = first;
            int data;
            if (first->next == NULL) {
                data = temp->data;
                delete temp;
                temp = back = first = NULL;
            } else {
                data = temp->data;
                first = first->next;
                delete temp;
                temp = NULL;
            }
            return data;
        }
};

#endif