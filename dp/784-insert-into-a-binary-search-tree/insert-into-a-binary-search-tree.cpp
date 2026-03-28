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
    void solve(TreeNode* root, int v){
        if(root->left ==NULL && root->right ==NULL){
            if(root->val > v) root->left = new TreeNode(v);
            else root->right = new TreeNode(v);
            return;
        }
   
        if(root->val > v){
            if(root->left!=NULL) solve(root->left , v);
            else{ 
              root->left = new TreeNode(v);
              return;
            }
        }

        if(root->val < v){
            if(root->right!=NULL) solve(root->right , v);
            else{ 
              root->right = new TreeNode(v);
              return;
            }
        }
     
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        solve(root,val);
        return root; 
    }
};