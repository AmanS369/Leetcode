class Solution {
public:
    pair<int, bool> help(TreeNode* root) {
        if (root == NULL) return {0, true}; 
        pair<int, bool> left = help(root->left);
        pair<int, bool> right = help(root->right);

       
        int height = max(left.first, right.first) + 1;
        bool isBalanced = left.second && right.second && (abs(left.first - right.first) <= 1);

        return {height, isBalanced};
    }

    bool isBalanced(TreeNode* root) {
        return help(root).second;
    }
};
