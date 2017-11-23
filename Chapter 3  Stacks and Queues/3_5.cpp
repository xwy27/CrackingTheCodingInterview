/* A graph to help:
        Stack1      Stack2
        QueueEnd    QueueStart
            1            8
            2            7
            3            6
            4            5
            |            ^
            V____________|
*/

#include "Stack.hpp"

class MyQueue {
    private:
        Stack s1, s2;
        int size;
    public:
        MyQueue() {
            size = 0;
        }

        ~MyQueue() = default;

        int Size() const {
            return s1.Size() + s2.Size();
        }

        bool enQueue(int data) {
            s1.push(data);
            return true;
        }

        int deQueue() {
            if (!s2.empty())    return s2.pop();
            while (!s1.empty()) s2.push(s1.pop());
            return s2.pop();
        }

        int start() {
            if (!s2.empty())    return s2.top();
            while (!s1.empty()) s2.push(s1.pop());
            return s2.top();
        }
};

int main() {
    MyQueue test;
    int i, count, data;
    cin >> count;
    for (i = 0; i < count; i++) {
        cin >> data;
        test.enQueue(data);
    }
    for (i = 0; i < count; i++) {
        cout << test.deQueue() << " ";
    }
    cout << endl;
}