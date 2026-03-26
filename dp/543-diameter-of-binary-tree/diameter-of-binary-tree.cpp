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
int maxi =0;
   int solve(TreeNode* root){
        if(root->right ==NULL && root->left==NULL) return 1;
        int left = 0;
        int right = 0;
        if(root->right!=NULL) right =  solve(root->right);
        if(root->left!=NULL) left = solve(root->left);
       

        maxi = max(left+right,maxi);
        return max(left,right) + 1;

   }
    int diameterOfBinaryTree(TreeNode* root) {
       int ans = solve(root);
       return maxi;
    }
};