/*
    On every node, we look “up” to see if we’ve found the sum.
    That is—rather than asking “does this node start a path with the sum?”, 
    we ask “does this node complete a path with the sum?”
*/

#include <iostream>
#include <vector>

using namespace std;

typedef struct treeNode {
    int data;
    treeNode *left;
    treeNode *right;
}treeNode;

treeNode* buildTree(int* pre, int* in, int size) {
    if (size == 0)  return NULL;
    int i;
    for (i = 0; i < size; ++i) {
        if (in[i] == *pre)   break;
    }
    treeNode* temp = new treeNode;
    temp->data = in[i];
    temp->left = buildTree(pre+1,in,i);
    temp->right = buildTree(pre+i+1,in+i+1,size-i-1);
    return temp;
}

char symbol[]={"-/\\<"};
void treeGraph(treeNode* root, int level) {
	int i;
	if (root != NULL) {
		treeGraph(root->right, level+1);
		for(i = 0; i < level; ++i)	putchar('\t');
		printf("%d ", root->data);
 
		putchar(symbol[((NULL!=(root->left))<<1)|(NULL!=(root->right))]);//determine the symbol to output
		putchar('\n');
		treeGraph(root->left, level+1);
	}
}

void print(vector<int> v, int start, int end) {
    for (int i = start; i <= end; ++i) {
        cout << v[i] << ( i == end ? "" : "->");
    }
    cout << endl;
}

void findPath(treeNode *root, int sum, vector<int> v, int level) {
    if (!root)  return;

    int temp = sum;
    v.push_back(root->data);
    for (int i = level; i >= 0; --i) {
        temp -= v[i];
        if (temp == 0)  print(v, i, level);
    }

    vector<int> copy1 = v;
    vector<int> copy2 = v;
    findPath(root->left, sum, copy1, level+1);
    findPath(root->right, sum, copy2, level+1);
}

int main() {
    int n = 9;
    int pre[] = {10,5,3,4,-2,2,1,-3,11};
    int in[] = {4,3,-2,5,2,1,10,-3,11};
    treeNode *root = buildTree(pre, in, n);
    treeGraph(root, 0);

    vector<int> v;
    int sum = 8;
    findPath(root, sum, v, 0);
}