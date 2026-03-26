class Solution {
public:
    TreeNode* prev = NULL;

    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        // check left subtree
        if (!isValidBST(root->left)) return false;

        // current node validation (STRICT check)
        if (prev != NULL && prev->val >= root->val) return false;

        prev = root;

        // check right subtree
        return isValidBST(root->right);
    }
};