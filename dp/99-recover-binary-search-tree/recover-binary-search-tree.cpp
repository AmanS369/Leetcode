
class Solution {
public:
    TreeNode* first ;
    TreeNode* last;
    TreeNode* prev;
    TreeNode* middle;
    void solve(TreeNode* root){
       if(root==NULL) return;
       solve(root->left);

       if(prev!= NULL && root->val < prev->val){
         if(first != NULL){
            last = root;
         }else{
            first = prev;
            middle = root;
         }
       }
       prev = root;

       solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        solve(root);
        if(last==NULL){
         swap(first->val,middle->val);
       }else swap(first->val,last->val);
    }
};