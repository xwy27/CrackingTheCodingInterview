#include <iostream>

using namespace std;

typedef struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;
    treeNode* parent;
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

void buildFather(treeNode *root) {
    if (root) {
        if (root->left) root->left->parent = root;
        if (root->right) root->right->parent = root;
        buildFather(root->left);
        buildFather(root->right);
    }
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

treeNode* leftMost(treeNode* root) {
    if (!root)  return NULL;
    while (root->left) {
        root = root->left;
    }
    return root;
}

treeNode* successor(treeNode* node) {
    if (node) {
        treeNode *result;
        if (!node->parent || node->right) {
            result = leftMost(node->right);
        } else {
            while ((result = node->parent) != NULL) {
                if (result->left == node)   break;
                node = result;
            }
        }
        return result;
    }
    return NULL;
}

int main() {
    int n = 8;
    int pre[] = {1,2,4,3,5,7,8,6};
    int in[] = {4,2,1,7,5,8,3,6};

    treeNode* root = buildTree(pre, in, n);
    buildFather(root);
    treeGraph(root, 0);
    
    treeNode* test[3]; 
    test[0] = root;
    test[1] = root->left;
    test[2] = root->right->left->right;

    for (int i = 0; i < 3; ++i) {
        if (successor(test[i])) {
            cout << "The next node of " 
                 << test[i]->data << " is "
                 << successor(test[i])->data << endl;
        }
    }
}