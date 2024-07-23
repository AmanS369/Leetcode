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
int maxPath=0;

void solve(TreeNode* root , bool flag, int cnt){
    if(root ==NULL) return ;
    maxPath = max(maxPath,cnt);
    if(flag){
        solve(root->left,!flag,cnt+1);
        solve(root->right,1,1);
    }else{
        solve(root->right,!flag,cnt+1);
        solve(root->left,0,1);
    }
    

}
    int longestZigZag(TreeNode* root) {
        solve(root->left,0,1);
        solve(root->right,1,1);
        return maxPath;
        
    }
};