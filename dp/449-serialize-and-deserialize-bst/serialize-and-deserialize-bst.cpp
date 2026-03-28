/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
void buildString(TreeNode* root, string &res) {
        if (root == NULL) {
            res += "#,";
            return;
        }

        res += to_string(root->val) + ",";
        buildString(root->left, res);
        buildString(root->right, res);
    }
  TreeNode* buildTree(queue<string> &q) {
        string val = q.front();
        q.pop();

        if (val == "#") return NULL;

        TreeNode* root = new TreeNode(stoi(val));
        root->left = buildTree(q);
        root->right = buildTree(q);

        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
         string res = "";
        buildString(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
          queue<string> q;
        string temp = "";
        for (char c : data) {
            if (c == ',') {
                q.push(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        return buildTree(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;