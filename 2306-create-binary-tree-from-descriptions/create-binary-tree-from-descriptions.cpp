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
     TreeNode* createBinaryTree(vector<vector<int>>& d) {
        map<int, TreeNode*> nodes;
        set<int> children;
        
        for (int i = 0; i < d.size(); i++) {
            int parent = d[i][0];
            int child = d[i][1];
            int dir = d[i][2];
            TreeNode* par = nullptr;
            TreeNode* chd = nullptr;

            if (nodes.find(parent) != nodes.end()) {
                par = nodes[parent];
            } else {
                par = new TreeNode(parent);
                nodes[parent] = par;
            }

            if (nodes.find(child) != nodes.end()) {
                chd = nodes[child];
            } else {
                chd = new TreeNode(child);
                nodes[child] = chd;
            }

            if (dir) {
                par->left = chd;
            } else {
                par->right = chd;
            }

            children.insert(child);
        }
//jo kiska childeren wahi parent banega 
//means jo children nhi vo set me nhi aayega  but map me ayega
        TreeNode* root = nullptr;
        for (auto& node : nodes) {
            if (children.find(node.first) == children.end()) {
                root = node.second;
                break;
            }
        }
        return root;
    }
};