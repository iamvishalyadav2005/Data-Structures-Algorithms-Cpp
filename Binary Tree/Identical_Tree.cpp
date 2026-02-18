#include <iostream>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        right ,left = NULL;
        
    }
};

class Solution {
public:
    bool isIdentical(TreeNode* p, TreeNode* q) {
        // If both nodes are NULL
        if (p == NULL && q == NULL)
            return true;

        // If one is NULL
        if (p == NULL || q == NULL)
            return false;

        // Check current value and recursively check left and right
        return (p->val == q->val) &&
               isIdentical(p->left, q->left) &&
               isIdentical(p->right, q->right);
    }
};
