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
    ListNode* deleteDuplicates(ListNode* head) {
          ListNode* dummy = new ListNode(0);
          dummy->next = head; 
          ListNode* prev = dummy;  
          ListNode* curr = head;


        while(curr!=nullptr){
            bool isDuplicate = false;
          while (curr->next != nullptr && curr->val == curr->next->val) {
            curr = curr->next;   // skip all same values
            isDuplicate = true;
        }
            if (isDuplicate) {
               prev->next = curr->next;  // prev stays, skip entire group
            } else {
              prev = prev->next;        // no duplicate, prev can move forward
            }

          curr = curr->next;
        }
        return dummy->next;
    }
};