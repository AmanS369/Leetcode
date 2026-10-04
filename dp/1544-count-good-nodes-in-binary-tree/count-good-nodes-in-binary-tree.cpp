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
    int solve(TreeNode* root,int maxV){
          if(root==NULL) return 0;
          int rootVal = root->val;

          int ans = 0;
          if(rootVal >=maxV){
            ans = 1 + solve(root->left,rootVal) + solve(root->right,rootVal);
          }else  ans = solve(root->left,maxV) + solve(root->right,maxV);

          return ans;
    }
    int goodNodes(TreeNode* root) {
        return solve(root,root->val);
    }
};