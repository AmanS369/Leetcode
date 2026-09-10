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
int res = 0;
    pair<int,int> solve(TreeNode* root){
        if(root == NULL) return {0,0};
        if(root->left==NULL && root->right == NULL){
            res+=1;
            return {root->val,1};
        }
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);

      

        int count = (left.second + right.second)+1;
        int sum = (root->val +left.first + right.first);
        int avg  = sum/count;
        if(avg == root->val ){
            res+=1;
        }
        return {sum,count};
        
    }
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL) return 0;

        solve(root);
        return res;
    }
};