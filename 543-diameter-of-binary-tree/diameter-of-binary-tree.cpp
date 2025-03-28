class Solution {
public:
    int maxD = 0;
    
    int D(TreeNode* root) {
        if (root == NULL) return 0;

        int left = D(root->left);
        int right = D(root->right);
        
      
        maxD = max(maxD, left + right);
        
     
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        D(root);
        return maxD;
    }
};
