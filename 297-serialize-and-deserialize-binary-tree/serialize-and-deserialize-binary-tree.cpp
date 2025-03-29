class Codec {
public:
   
    void dfs(TreeNode* root, string &ans) {
        if (root == NULL) {
            ans += "N|"; 
            return;
        }
        ans += to_string(root->val) + "|";
        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    string serialize(TreeNode* root) {
        string ans = "";
        dfs(root, ans);
        return ans;
    }

   
    TreeNode* buildTree(vector<string>& arr, int &index) {
        if (index >= arr.size() || arr[index] == "N") {
            index++;
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(arr[index]));
        index++;
        root->left = buildTree(arr, index);
        root->right = buildTree(arr, index);
        return root;
    }

    TreeNode* deserialize(string data) {
        vector<string> arr;
        stringstream ss(data);
        string token;

       
        while (getline(ss, token, '|')) {
            arr.push_back(token);
        }

        
        int index = 0;
        return buildTree(arr, index);
    }
};