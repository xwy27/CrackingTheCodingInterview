/* 
    Search T1 to find the root node of T2
    Once find, start match all the nodes of T2 with T1
    If T2 is T1's subTree, return true
    Else return false
*/

//Function codes are written

#include <iostream>

using namespace std;

typedef struct treeNode {
    int data;
    treeNode *left;
    treeNode *right;
}treeNode;

bool match(treeNode* r1, treeNode* r2){
    if(r1 == NULL && r2 == NULL)    return true;
    else if(r1 == NULL || r2 == NULL)   return false;
    else if(r1->key != r2->key) return false;
    else return match(r1->lchild, r2->lchild) && match(r1->rchild, r2->rchild);
}

bool subtree(treeNode* r1, treeNode* r2){
    if(r1 == NULL)  return false;
    else if(r1->key == r2->key) {
        if(match(r1, r2))   return true;
    }
    else return subtree(r1->left, r2) || subtree(r1->right, r2);
}

bool containTree(treeNode* r1, treeNode* r2){
    if(r2 == NULL)  return true;
    else return subtree(r1, r2);
}