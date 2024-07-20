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
int nodes=0;
    pair<int,int> help(TreeNode* root){
        if(!root) return {0,0};
        if(root->left==NULL && root->right==NULL) {nodes+=1;return {root->val,1};}
        pair<int,int>left = help(root->left);
        pair<int,int>right = help(root->right);
        int newSum = left.first + right.first + root->val;
        int newElement = left.second + right.second + 1;
        if(root->val ==  (newSum/newElement)) nodes+=1;
        return {newSum,newElement};
    }
    int averageOfSubtree(TreeNode* root) {
        help(root);
        return nodes;
    }
};