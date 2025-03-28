
class Solution {
public:
    
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        int left =0;
        int right=0;
        if(root->left!=NULL) left = maxDepth(root->left);
        if(root->right!=NULL) right = maxDepth(root->right);
        return 1 + max(left,right);
    }
};