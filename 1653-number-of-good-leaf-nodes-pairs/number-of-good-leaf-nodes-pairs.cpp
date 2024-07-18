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
int goodPair=0;
    vector<int>help(TreeNode* root, int d){
        if(!root) return {};
        if(root->left==NULL && root->right==NULL) return {1};
        vector<int>left = help(root->left,d);
          vector<int>right = help(root->right,d);
          for(auto i:left){
            for(auto j:right){
                if(i+j<=d) goodPair++;
            }
          }

          vector<int>parent;
          for(auto i:left) {
            if(i<=d) parent.push_back(i+1);
          }

            for(auto i:right) {
            if(i<=d) parent.push_back(i+1);
          }

          return parent;
    }
    int countPairs(TreeNode* root, int distance) {
        help(root,distance);
        return goodPair;
    }
};