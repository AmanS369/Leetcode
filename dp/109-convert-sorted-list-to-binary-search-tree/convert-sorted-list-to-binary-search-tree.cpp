/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve1(vector<int>data,int i , int j){
        if(i > j || i<0) return NULL;
        
        int mid = i + (j - i) / 2;
        TreeNode* left = solve1(data,i,mid-1);
        TreeNode* right = solve1(data,mid+1,j);
        TreeNode* root = new TreeNode(data[mid]);

        root->left = left;
        root->right = right;

        return root;
        
    }
    ListNode* curr;
    TreeNode* solve(int n){
        if(n<=0) return NULL;
        TreeNode* left = solve(n / 2);
        TreeNode* root = new TreeNode(curr->val);
        curr = curr->next;
        TreeNode* right  = solve(n - n/2 - 1);
        root->left = left;
        root->right = right;
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        // vector<int>data;
        // while(head!=NULL){
        //     data.push_back(head->val);
        //     head = head->next;
        // }
        // return solve(data,0,data.size()-1);
         int n = 0;
        ListNode* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        curr = head;

        return solve(n);
    }
};