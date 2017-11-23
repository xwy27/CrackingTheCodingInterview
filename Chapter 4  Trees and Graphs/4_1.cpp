#include <iostream>
using namespace std;

int max(int &a, int &b) {
    return a > b ? a : b;
}

int min(int &a, int &b) {
    return a > b ? b : a;
}

typedef struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;
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

int maxDepth(treeNode* root) {
    if (root == NULL)   return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(treeNode* root) {
    if (root == NULL)   return 0;
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

bool isBalance(treeNode* root) {
    return (maxDepth(root) - minDepth(root) <= 1);
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

int main() {
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

    cout << maxDepth(root) << endl;
    cout << minDepth(root) << endl;

    cout << "Is" << (isBalance(root) ? " " : " not ")
         << "balance" << endl;
}