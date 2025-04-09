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
    int index=0;
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if ( preorder.size() == 0) return NULL;
        TreeNode *root = new TreeNode(preorder[0]);  
        stack<TreeNode*>st;
        st.push(root); 

        int i =1;
        while(i<preorder.size()){
            TreeNode* node = new TreeNode(preorder[i]); 
            TreeNode* curr = st.top();
            if(node->val < curr->val){
                curr->left = node;
            }else{
                while(!st.empty() && node->val > st.top()->val){
                    curr = st.top();
                    st.pop();
                }
                curr->right = node;
            }
            st.push(node);
            i++;
        }
        return root;
    }
};