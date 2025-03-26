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

vector<int> inorderTraversal;

void inorder(TreeNode* root) {
    if (root == NULL) return;  

    inorder(root->left); 

    inorderTraversal.push_back(root->val); 

    inorder(root->right);  
}
TreeNode* last = NULL;
    bool isValidBST(TreeNode* root) {
    //    inorder(root);
    //    for(int i=1;i<inorderTraversal.size();i++){
    //     if(inorderTraversal[i] <= inorderTraversal[i-1]) return false;
    //    }
    //    return true;

    if(root==NULL) return true;
     if(!isValidBST(root->left)) return false; 

     if(last!=NULL && last->val>=root->val) return false;
     last = root;
     if(!isValidBST(root->right)) return false; 
     return true;


    }
};