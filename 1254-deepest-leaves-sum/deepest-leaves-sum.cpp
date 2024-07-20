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
    int deepestLeavesSum(TreeNode* root) {
     queue<TreeNode*>q;
     q.push(root);
     int ans=0;
     while(!q.empty()){
        int sz = q.size();
        if(sz <= 0) break;
        int tempAns = 0;
        while(sz--){
            TreeNode* frontNode = q.front();
            tempAns+=frontNode->val;
            q.pop();
            if(frontNode->left) q.push(frontNode->left);
            if(frontNode->right) q.push(frontNode->right);
            
        }
        ans = tempAns;
     }

     return ans;

    }
};