#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "node.hpp"

using std::cin;
using std::cout;
using std::endl;

class Stack{
    private:
        node* Top;
        int size;
    public:
        Stack() {
            size = 0;
            Top = NULL;
        }
        
        ~Stack() {
            node* temp = Top;
            while (temp != NULL) {
                Top = Top->next;
                delete temp;
                temp = Top;
            }
            temp = Top = NULL;
            size = 0;
        }
        
        bool empty() const {
            return size == 0;
        }

        int Size() const {
            return size;
        }

        bool push(int data) {
            node* temp = new node(data);
            temp->next = Top;
            Top = temp;
            size++;
            return true;
        }

        int pop() {
            if (!empty()) {
                int val = Top->data;
                node* temp = Top;
                Top = Top->next;
                delete temp;
                temp = NULL;
                size--;
                return val;
            }
            return -1;
        }

        int popButtom() {
            if (!empty()) {
                if (size == 1) {
                    int val = pop();
                    return val;
                } else {
                    node* temp = Top;
                    node* pre = NULL;
                    int num = size-1;
                    while (num > 0) {
                        pre = temp;
                        temp = temp->next;
                        num--;
                    }
                    pre->next = temp->next;
                    int val = temp->data;
                    delete temp;
                    temp = NULL;
                    size--;
                    return val;
                }
            }
            return -1;
        }

        int top() const {
            if (!empty())   return Top->data;
            return -1;
        }

        int get(int index) {
            if (index <0 || index >= size)    return -1;
            node* temp = Top;
            while (index-- && temp != NULL) {
                temp = temp->next;
            }
            return temp->data;
        }
};

#endif