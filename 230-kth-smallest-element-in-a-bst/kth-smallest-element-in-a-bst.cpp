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
int ans =0;
int Rem =0;

   void help(TreeNode* root){
    if(root->left!=NULL)help(root->left);
    if(Rem>0){
        Rem--;
        if(Rem==0){
            ans=root->val;
            return;
        }
    }
    if(root->right!=NULL)help(root->right);
   }

   
    int kthSmallest(TreeNode* root, int k) {
        Rem = k;
        help(root);
        return ans;
    } 
};