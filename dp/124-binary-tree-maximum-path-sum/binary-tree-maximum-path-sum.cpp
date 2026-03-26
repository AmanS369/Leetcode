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
    int maxSum=INT_MIN;
    int  solve(TreeNode* root){
        if(root==NULL) return 0;
        int  left = max(0,solve(root->left));
        int right = max(0,solve(root->right));
        int sumL = left + root->val;
        int sumR = right + root->val;
        int sumA = left + root->val + right;
        maxSum = max(maxSum,sumA);

        return max(sumL , sumR);
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->val;
        int sum = solve(root);
        return maxSum;
    }
};