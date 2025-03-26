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
    TreeNode* rightEnd(TreeNode* root){

        while (root->left != nullptr) 
            root = root->left;
        return root;
     }

    TreeNode* deleteNode(TreeNode* root, int key) {
      if(root==NULL) return NULL;

      if( key < root->val){
        root->left = deleteNode(root->left,key);
      }else if(key > root->val){
        root->right = deleteNode(root->right,key);
      }else{
        if(root->left==NULL && root->right!=NULL)root = root->right;
        else if( root->right==NULL && root->left!=NULL) root = root->left;
        else if( root->right==NULL && root->left==NULL) root =  NULL;
        else{
            TreeNode* leftpart = rightEnd(root->right);
            leftpart->left = root->left;
            root = root->right;

        }
        
      }

      return root;
       
    }
};