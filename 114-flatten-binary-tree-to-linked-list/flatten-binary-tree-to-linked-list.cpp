
class Solution {
public:
   TreeNode* solve(TreeNode* root){
    if(root==NULL) return NULL;
    TreeNode* leftTree = solve(root->left);
    TreeNode* rightTree = solve(root->right);
    if(leftTree){
        TreeNode* rightmost = leftTree;
        while(rightmost->right) rightmost = rightmost->right;
        rightmost->right = rightTree;
        root->right = leftTree;
        root->left = NULL;
    }else root->right = rightTree;

    return root;
   }
    void flatten(TreeNode* root) {
        solve(root);
    }
};