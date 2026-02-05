//Lowest Common Ancestor (LCA) in a Binary Tree
// We use DFS (post-order traversal):
// If the current node is NULL → return NULL
// If the current node is p or q → return current node
// Recur for left and right
  //If both left and right are non-NULL → current node is the LCA
  //Else return the non-NULL one
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left != NULL && right != NULL)
            return root;

        return (left != NULL) ? left : right;
    }

