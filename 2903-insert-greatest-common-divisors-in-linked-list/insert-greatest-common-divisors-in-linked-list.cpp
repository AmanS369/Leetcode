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
class Solution {
public:
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==NULL) return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while(curr!=NULL){
            int num = gcd(prev->val,curr->val);
            ListNode* temp = prev;
            prev=curr;
            ListNode* newNode = new ListNode(num);
            temp->next = newNode;
            newNode->next = curr;
            curr = curr->next;
        }
        return head;
    }
};