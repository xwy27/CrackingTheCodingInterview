//Using vector as a linked list
#include <iostream>
#include <vector>
using namespace std;

const int MAXSIZE = 1000;

typedef struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;
}treeNode;

treeNode* buildTree(int *pre, int *in, int size) {
    if (size <= 0)  return NULL;

    int i;
    for (i = 0; i < size; ++i) {
        if (*pre == in[i])  break;
    }
    treeNode* temp = new treeNode;
    temp->data = in[i];
    temp->left = buildTree(pre+1, in, i);
    temp->right = buildTree(pre+i+1, in+i+1, size-i-1);
    return temp;
}

char symbol[] = {"-/\\<"};
void treeGraph(treeNode *root, int level) {
    int i;
    if (root) {
        treeGraph(root->right, level+1);
        for (i = 0; i < level; ++i) cout << "\t";
        cout << root->data << " ";
        cout << symbol[((NULL!=root->left)<<1)|(NULL!=root->right)] << endl;
        treeGraph(root->left, level+1);
    }
}

int levelNodeList(treeNode *root, vector<treeNode> result[]) {
    int level = 0;
    result[level].push_back(*root);
    while (1) {
        for (int i = 0; i < result[level].size(); ++i) {
            treeNode *temp = &result[level][i];
            if (temp) {
                if (temp->left) result[level+1].push_back(*(temp->left));
                if (temp->right) result[level+1].push_back(*(temp->right));
            }
        }
        if (result[level+1].size() <= 0)    break;
        level++;
    }
    return level+1;
}

void showNodeList(vector<treeNode> result[], int level) {
    for (int i = 0; i < level; ++i) {
        cout << i << ": ";
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j].data << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<treeNode> result[MAXSIZE+1];
    int n;
    cin >> n;
    int *pre = new int[n];
    int *in = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> pre[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> in[i];
    }
    treeNode* root = buildTree(pre, in, n);
    treeGraph(root, 0);
    int level = levelNodeList(root, result);
    // cout << level << endl;
    showNodeList(result, level);
}
