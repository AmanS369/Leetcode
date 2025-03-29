
class Solution {
public:
    vector<vector<int>>ans;
    void help(TreeNode* root, int targetSum,vector<int>&output,int sum){
        if(root==NULL) return;
        output.push_back(root->val);
        sum+=root->val;
        if(root->left==NULL && root->right==NULL){
            
            if(sum==targetSum){
           
                ans.push_back(output);
            }
        }
 
        help(root->left,targetSum,output,sum);
        help(root->right,targetSum,output,sum);
        output.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<int>output;
       help(root,targetSum,output,0);
       return ans; 
    }
};