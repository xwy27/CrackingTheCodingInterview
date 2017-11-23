#include "Stack.hpp"

void sort(Stack& s, Stack& r) {
    int temp;
    while (!s.empty()) {
        temp = s.pop();
        while (!r.empty() && r.top() > temp) {
            s.push(r.pop());
        }
        r.push(temp);
    }
}

int main() {
    Stack test, sorted;
    int i, count, data;
    cin >> count;
    for (i = 0; i < count; i++) {
        cin >> data;
        test.push(data);
    }
    sort(test, sorted);
    for (i = 0; i < count; i++) {
        cout << sorted.pop() << " ";
    }
    cout << endl;
}