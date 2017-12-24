#include "Stack.hpp"

#define Limit 5

class SetOfStacks {
    private:
        Stack* set;
        int count;
        int Capicity;
    public:
        SetOfStacks() {
            Capicity = 20;
            count = 0;
            set = new Stack[Capicity/Limit];
        }

        ~SetOfStacks() {
            if (count > 0) delete []set;
            set = NULL;
            count = 0;
        }

        bool push(int data) {
            if (count == Capicity)  extend();
            set[count/Limit].push(data); 
            count++;
            return true;
        }

        int pop() {
            if (count <= 0) return -1;
            int temp = -1;
            if (count % 5 == 0) temp = set[count/Limit - 1].pop();
            else    temp = set[count/Limit].pop();
            count--;
            return temp;
        }

        int top() const {
            if (count % 5 == 0) return set[count/Limit - 1].top();
            return set[count/Limit].top();
        }

        void extend() {
            int arr[Capicity];

            for (int i = 0; i < Capicity; ++i)  arr[i] = pop();
            
            delete []set;
            set = new Stack[Capicity/Limit*2];
            
            for (int i = 0; i < Capicity; ++i)  push(arr[i]);
            
            Capicity *= 2;
        }

        int left(int num, bool flag) {
            int temp;
            if (flag) {
                temp = set[num].pop();
            } else {
                temp = set[num].popButtom();
            }

            int sizes = 0;
            if (count % Limit == 0) {
                sizes = count / Limit;
            } else {
                sizes = count / Limit + 1;
            }
            if (set[num].empty()) {
            } else if (sizes > (num + 1)) {
                int val = left(num+1, false);
                set[num].push(val);
            }
            return temp;
        }

        int popAt(int num) {
            if (num < 0 || num >= Capicity / Limit)  return -1;
            int val = left(num, true);
            count--;
            return val;
        }
};

int main() {
    SetOfStacks test;
    int i, count, data;
    cin >> count;
    for (i = 0; i < count; i++) {
        cin >> data;
        test.push(data);
    }
    cin >> data;
    cout << "pop: " << test.popAt(data) << endl;
    for (i = 0; i < count - 1; i++) {
        cout << test.pop() << " ";
    }
    cout << endl;
    return 0;
}