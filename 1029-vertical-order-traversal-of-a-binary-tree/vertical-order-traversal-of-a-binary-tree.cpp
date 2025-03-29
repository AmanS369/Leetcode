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
 unordered_map<int,map<int,vector<int>>>mp;
 int minLevel =INT_MAX;
 int maxLevel = INT_MIN;
 void dfs(TreeNode* root,int vLevel,int hLevel){
    if(root==NULL) return;
    minLevel = min(minLevel,vLevel);
    maxLevel = max(maxLevel,vLevel);
    mp[vLevel][hLevel].push_back(root->val); 
    dfs(root->left,vLevel-1,hLevel+1);
    dfs(root->right,vLevel+1,hLevel+1);
 }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        int size = abs(minLevel) + abs(maxLevel) + 1;
        vector<vector<int>>ans(size);
        for(auto[key,Vvalue]:mp){
           for(auto [hkey,hValue]:Vvalue){
              sort(hValue.begin(),hValue.end());
              for(auto i : hValue) ans[key + abs(minLevel)].push_back(i);
           }
        }

        return ans;
    }
};