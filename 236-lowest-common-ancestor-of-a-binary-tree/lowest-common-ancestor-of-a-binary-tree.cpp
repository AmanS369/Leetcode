/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q) return root;
        TreeNode* leftLCA = NULL;
        TreeNode* rightLCA = NULL;
        if(root->left!=NULL)leftLCA= lowestCommonAncestor(root->left,p,q);
        if(root->right!=NULL)rightLCA = lowestCommonAncestor(root->right,p,q);
        if(leftLCA!=NULL && rightLCA==NULL) return leftLCA;
        else if(leftLCA==NULL && rightLCA!=NULL) return rightLCA;
        else if(leftLCA!=NULL && rightLCA!=NULL) return root;
        return NULL;
    }
};