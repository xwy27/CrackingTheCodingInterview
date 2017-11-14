#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef struct node {
    int data;
    node* next;
    node(int val = 0) : data(val), next(NULL) {}
}node;

class linkedList {
    private:
        node* head;
        int size;
    public:
        linkedList() {
            head = NULL;
            size = 0;
        }

        linkedList(linkedList &list) {
            node* cur = list.head;
            while (cur != NULL) {
                head = new node(cur->data);
                cur = cur->next;
            }
            size = list.size;
        }

        ~linkedList() {
            node* temp = head;
            while (temp != NULL) {
                head = temp;
                temp = temp->next;
                delete head;
            }
            head = temp = NULL;
            size = 0;
        }

        int Size() const {
            return size;
        }

        bool empty() const {
            return !size;
        }

        bool insert(int pos, int val) {
            if (pos < 0 || pos > size)  return false;
            node* temp = new node(val);
            if (temp != NULL) {
                if (pos == 0 && head == NULL) {
                    head = temp;   
                } else if (pos == 0 && head != NULL) {
                    temp->next = head->next;
                    head = temp;
                } else {
                    node* cur = head;
                    node* pre = NULL;
                    while (pos > 0 && cur != NULL) {
                        pre = cur;
                        cur = cur->next;
                        --pos;
                    }
                    pre->next = temp;
                    temp->next = cur;
                }
                size++;
                return true;
            }
            return false;
        }

        bool insert(int pos, node* data) {
            if (pos < 0 || pos > size)  return false;
            if (data != NULL) {
                if (pos == 0 && head == NULL) {
                    head = data;
                } else if (pos == 0 && head != NULL) {
                    data->next = head->next;
                    head = data;
                } else {
                    node* cur = head;
                    node* pre = NULL;
                    while (pos > 0 && cur != NULL) {
                        pre = cur;
                        cur = cur->next;
                        --pos;
                    }
                    pre->next = data;
                    data->next = cur;
                }
                size++;
                return true;
            }
            return false;
        }

        bool remove(int pos, int &val) {
            if (pos < 0 || pos >= size)  return false;
            if (head == NULL)   return false;
            node* pre = NULL;
            node* cur = head;
            if (pos == 0) {
                head = cur->next;
                delete cur;
                cur = NULL;
            } else {
                while (pos > 0 && cur != NULL) {
                    pre = cur;
                    cur = cur->next;
                    --pos;
                }
                pre->next = cur->next;
                delete cur;
                cur = NULL;
            }
            --size;
            return true;
        }

        void show() {
            node* temp = head;
            while (temp != NULL) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }

        void removeDup();//function for question 1

        int nthToLast(int n);//function for question 2

        void removeMid(node* middle);//function for question 3

        void addList(linkedList &list, linkedList &result);//function for question 4

        //function for question 5
        void circular(int pos);
        void removeCir();
        node* startOfLoop();
};

#endif