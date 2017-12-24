/* One problem:
    Once pop the min element in stack, the min method return what num?
    Choose to return a big num, since the min method can only be O(1).
*/

#include "Stack.hpp"

#define max 999999

class stack {
    private:
        Stack test;
        Stack Min;
    public:
        stack() {
            Min.push(max);
        }

        ~stack() = default;

        bool push(int val) {
            test.push(val);
            if (val < Min.top()) {
                Min.pop();
                Min.push(val);
            }
            return true;
        }

        int pop() {
            int temp = test.pop();
            if (temp == Min.top()) {
                Min.pop();
                Min.push(max);
            }
            return temp;
        }

        int min() const {
            if (Min.empty())    return max;
            return Min.top();
        }
};

int main() {
    stack Test;
    int i, count, data;
    cin >> count;
    for (i = 0; i < count; i++) {
        cin >> data;
        Test.push(data);
    }
    cout << Test.min() << endl;
    for (i = 0; i < count; i++) {
        cout << Test.pop() << " ";
    }
    cout << endl << Test.min() << endl;
}