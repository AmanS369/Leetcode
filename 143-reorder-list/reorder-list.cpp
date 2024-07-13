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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return; 
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        
        prev->next = nullptr;  
        ListNode* secondHalf = reverseList(slow);

        // Step 2: Merge the two halves
        ListNode* firstHalf = head;
        while (firstHalf && secondHalf) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;
            
            firstHalf->next = secondHalf;
            if (temp1 == nullptr) break; // Handle the end of the list
            secondHalf->next = temp1;
            
            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
};
