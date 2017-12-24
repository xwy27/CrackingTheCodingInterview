#include "Stack.hpp"

class Tower
{
private:
    Stack disks;
    int index;
public:
    Tower() = default;

    Tower(int i) {
        index = i;
    }

    ~Tower() = default;
    
    void setIndex(int i) {
        index = i;
    }

    void add(int d) {
        if (!disks.empty() && disks.top() <= d) {
            cout << "Error placing" << endl;
        } else {
            disks.push(d);
        }
    }

    void moveTopTo(Tower &t) {
        int top = disks.pop();
        if (top >= 0) {
            t.add(top);
            cout << "Move disk " << top << " from " << index << " to " << t.index << endl;
        }
    }

    void print() {
        cout << "Contents of Tower " << index << endl;
        for (int i = disks.Size() - 1; i >= 0; --i) {
            cout << "   " << disks.get(i);
        }
    }

    void moveDisks(int n, Tower &destination, Tower &buffer) {
        if (n > 0) {
            moveDisks(n-1, buffer, destination);
            moveTopTo(destination);
            buffer.moveDisks(n-1, destination, *this);
        }
    }
};

int main() {
    int n = 4;
    Tower* towers = new Tower[n];
    for (int i = 0; i < 3; ++i) towers[i].setIndex(i);
    for (int i = n-1; i >= 0; --i)    towers[0].add(i);
    towers[0].moveDisks(5, towers[2], towers[1]);
    delete []towers;
}
