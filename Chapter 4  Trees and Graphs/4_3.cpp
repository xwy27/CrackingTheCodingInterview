#include <iostream>
#include <cstdio>
using namespace std;

typedef struct treeNode {
    int val;
    treeNode* left;
    treeNode* right;
}treeNode;

treeNode* addToTree(int* arr, int start, int end) {
    if (end < start)    return NULL;

    int mid = (start + end ) / 2;
    treeNode* temp = new treeNode;
    temp->val = arr[mid];
    temp->left = addToTree(arr, start, mid-1);
    temp->right = addToTree(arr, mid+1, end);
    return temp;
}

char symbol[] = {"-/\\<"};
void treeGraph(treeNode* root, int level) {
    int i;
    if (root != NULL) {
        treeGraph(root->right, level+1);
        for (i = 0; i < level; ++i) cout << "\t";
        cout << root->val << " ";
        cout << symbol[((NULL!=root->left)<<1)|(NULL!=root->right)] << endl;
        treeGraph(root->left, level+1);
    }
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    treeNode* root = addToTree(arr, 0, n-1);

    treeGraph(root,0);
}