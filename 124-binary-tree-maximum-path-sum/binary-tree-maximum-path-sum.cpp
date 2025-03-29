/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxi=INT_MIN;
    int help(TreeNode* root){
        if(root==NULL) return 0;
       
        int left = max(0,help(root->left));
        int right = max(0,help(root->right));
        int ans = root->val + max(left,right);
        maxi= max(maxi,left+right+root->val);
        return ans;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->val;
        help(root);
        return maxi;
    }
};