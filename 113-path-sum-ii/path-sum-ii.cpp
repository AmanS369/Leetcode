
class Solution {
public:
    vector<vector<int>>ans;
    void help(TreeNode* root, int targetSum,vector<int>output,int sum){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            sum+=root->val;
            if(sum==targetSum){
                output.push_back(root->val);
                ans.push_back(output);
            }
        }
        output.push_back(root->val);
        sum+=root->val;
        help(root->left,targetSum,output,sum);
        help(root->right,targetSum,output,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<int>output;
       help(root,targetSum,output,0);
       return ans; 
    }
};