class Solution {
public:
    
    TreeNode* findRightmost(TreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;  

        if (key < root->val) {
            root->left = deleteNode(root->left, key); 
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);  
        } else {
            // Node to be deleted found
            if (root->left == nullptr ) {
                TreeNode* temp = root->right;
                delete root;
                return temp;  
            } else if (root->right == nullptr ) {
                TreeNode* temp = root->left;
                delete root;
                return temp;  
            } else {
               
                TreeNode* rightmost = findRightmost(root->left);
                root->val = rightmost->val;  
                root->left = deleteNode(root->left, rightmost->val);  
            }
        }

        return root;
    }
};
