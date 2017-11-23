#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXSIZE = 1000;

typedef struct Node {
    int value;
    Node(int val) : value(val){};
}Node;

bool isPath(int begin, int end, vector<Node> v[MAXSIZE+1]) {
    bool visit[MAXSIZE] = {0};

    Node node(begin);
    visit[begin] = true;
    queue<Node> q;
    q.push(node);
    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        int val = cur.value;
        int size = v[val].size();
        for (int i = 0; i < size; ++i) {
            Node temp = v[val].at(i);
            if (visit[temp.value])  continue;
            visit[temp.value] = true;
            q.push(temp);
        }
    }

    if (visit[end]) return true;
    return false;
}

int main() {
    int nodeNum, edgeNum, front, back, begin, end; 
    
    while (cin >> nodeNum >> edgeNum) {
        vector<Node> v[MAXSIZE+1];
        for (int i = 0; i < edgeNum; ++i) {
            cin >> front >> back;
            if (front < 0 || back < 0)  continue;
            Node temp(back);
            v[front].push_back(temp);
        }

        cin >> begin >> end;
        cout << (isPath(begin, end, v) ? "Exist" : "No")
             << " Path" << endl;
    }

} 