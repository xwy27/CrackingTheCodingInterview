/*
判断子树中是否存在某节点（时间复杂度O(N^2)）
首先建立一个方法判断一棵树中是否存在某个节点，这个比较简单，只需要遍历整棵树，如果存在返回true，如果不存在则返回false。
接下来的判断过程就遍历左子树或者右子树。
（1）如果题目给的两个节点都在右子树，那么继续遍历当前节点的右子树
（2）如果题目给的两个节点都在左子树，那么继续遍历当前节点的左子树
（3）如果给定的两个节点一个在左子树，一个在右子树，则返回当前节点。 
*/

#include <iostream>

using namespace std;

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

bool covers(treeNode* root, treeNode *p) {
    if (!root)  return false;
    if (root == p)  return true;
    return covers(root->left, p) || covers(root->right, p);
}

treeNode* commonAncestor(treeNode *root, treeNode *p, treeNode *q) {
    if (!root)  return NULL;
    if (root == p || root == q) return root;

    bool pInLeft = covers(root->left, p);
    bool qInLeft = covers(root->left, q);
    if (pInLeft != qInLeft)  return root;
    treeNode* temp = pInLeft ? root->left : root->right;
    return commonAncestor(temp, p ,q);
}

int main() {
    int n = 8;
    int pre[] = {1,2,4,3,5,7,8,6};
    int in[] = {4,2,1,7,5,8,3,6};

    treeNode* root = buildTree(pre, in, n);
    treeGraph(root, 0);

    treeNode* p[3];
    treeNode* q[3];
    p[0] = root->right->left->left;
    q[0] = root->right->left->right;
    p[1] = root->left->left;
    q[1] = root->right->left->right;
    p[2] = root->right->right;
    q[2] = root->right->left->right;

    for (int i = 0; i < 3; ++i) {
        cout << "The common ancestor of "
             << p[i]->data << " and " << q[i]->data
             << " is " << commonAncestor(root, p[i], q[i])->data << endl;
    }
}