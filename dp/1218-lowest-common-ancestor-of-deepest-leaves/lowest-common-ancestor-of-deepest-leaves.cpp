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
   
    pair<int, TreeNode*> solve(TreeNode* root){
        if(root==NULL) return {0,NULL};
        if(root->left ==NULL && root->right ==NULL){
            return {1,root};
        }
        pair<int, TreeNode*> lLca = solve(root->left);
        pair<int, TreeNode*> RLca = solve(root->right);

        if(lLca.first > RLca.first){
           return {lLca.first + 1 , lLca.second};
        }else if(lLca.first < RLca.first){
           return {RLca.first + 1 , RLca.second};
        }
         return {RLca.first + 1 , root};
    
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
         pair<int, TreeNode*> ans = solve(root);
        return ans.second;
    }
};