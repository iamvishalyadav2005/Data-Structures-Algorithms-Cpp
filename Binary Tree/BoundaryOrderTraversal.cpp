/***
Boundary Traversal of a binary tree means traversing the tree in anti-clockwise order starting from the root.
Boundary includes:
Root node
Left boundary (excluding leaf nodes)
All leaf nodes (left to right)
Right boundary (excluding leaf nodes, in reverse order)
  ***/
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    // Check if a node is leaf
    bool isLeaf(Node* node) {
        return (node->left == nullptr && node->right == nullptr);
    }

    // Add left boundary (excluding leaf nodes)
    void addLeftBoundary(Node* root, vector<int>& res) {
        Node* curr = root->left;
        while (curr) {
            if (!isLeaf(curr))
                res.push_back(curr->data);

            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    // Add all leaf nodes
    void addLeaves(Node* root, vector<int>& res) {
        if (!root) return;

        if (isLeaf(root)) {
            res.push_back(root->data);
            return;
        }

        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }

    // Add right boundary (excluding leaf nodes)
    void addRightBoundary(Node* root, vector<int>& res) {
        Node* curr = root->right;
        vector<int> temp;

        while (curr) {
            if (!isLeaf(curr))
                temp.push_back(curr->data);

            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        // Reverse right boundary before adding
        for (int i = temp.size() - 1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

    // Main function
    vector<int> boundaryTraversal(Node* root) {
        vector<int> res;
        if (!root) return res;

        if (!isLeaf(root))
            res.push_back(root->data);

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
};
