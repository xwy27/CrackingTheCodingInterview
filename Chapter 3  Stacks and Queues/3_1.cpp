#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int Stack[300];
int index[4] = {0,0,100,200};

bool push(int num, int val) {
    if (index[num] == num * 100 - 1 )    return false;
    Stack[index[num]] = val;
    index[num] = index[num] + 1;
    return true;
}

int pop(int num) {
    if (index[num] == (num - 1) * 100)    return -1;
    int temp = Stack[index[num]-1];
    Stack[index[num]] = 0;
    index[num] = index[num] - 1;
    return temp;
}

int top(int num) {
    if (index[num] == (num - 1) * 100)  return -1;
    return  Stack[index[num]];
}

int main() {
    int i, n1, n2, n3, data;
    cin >> n1 >> n2 >> n3;
    for (i = 0; i < n1; ++i) {
        cin >> data;
        push(1, data); 
    }
    for (i = 0; i < n2; ++i) {
        cin >> data;
        push(2, data);
    }
    for (i = 0; i < n3; ++i) {
        cin >> data;
        push(3, data);
    }
    for (i = 0; i < n1; ++i) {
        cout << pop(1) << " ";
    }
    cout << endl;
    for (i = 0; i < n2; ++i) {
        cout << pop(2) << " ";
    }
    cout << endl;
    for (i = 0; i < n3; ++i) {
        cout << pop(3) << " ";
    }
    cout << endl;
}