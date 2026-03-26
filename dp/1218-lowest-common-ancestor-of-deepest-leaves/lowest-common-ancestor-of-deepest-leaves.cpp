class Solution {
public:
    bool isAllSame(vector<TreeNode*> &deepestNode){
        TreeNode* curr = deepestNode[0];
        for(auto node : deepestNode){
            if(node != curr) return false;
        }
        return true;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == NULL) return NULL;

        unordered_map<TreeNode*, TreeNode*> parentMap;
        queue<vector<TreeNode*>> q;

        parentMap[root] = NULL;  // FIX: initialize root parent

        vector<TreeNode*> deepestNode;
        q.push({root});

        // BFS to get deepest level nodes
        while(!q.empty()){
            vector<TreeNode*> top = q.front();   // FIX: front(), not top()
            q.pop();

            vector<TreeNode*> newV;

            int i = 0;
            while(i < top.size()){
                if(top[i]->left != NULL){
                    parentMap[top[i]->left] = top[i];
                    newV.push_back(top[i]->left);
                }

                if(top[i]->right != NULL){
                    parentMap[top[i]->right] = top[i];
                    newV.push_back(top[i]->right);
                }

                i++;  // FIX: increment
            }

            if(!newV.empty()){
                deepestNode = newV;
                q.push(newV);
            }
        }

        if(deepestNode.size() == 0) return root;
        if(deepestNode.size() == 1) return deepestNode[0];

        // Move all deepest nodes upward until they meet
        while(true){
            for(int i = 0; i < deepestNode.size(); i++){
                if(deepestNode[i] != NULL)
                    deepestNode[i] = parentMap[deepestNode[i]];
            }

            if(isAllSame(deepestNode)) return deepestNode[0];
        }

        return NULL;
    }
};