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

class setPos {
public:
    int start;
    int curr;
    int prev;
    int mini;
    int maxi;

    setPos() {
        this->start = -1;
        this->curr = -1;
        this->prev = -1;
        this->mini=INT_MAX;
        this->maxi=INT_MIN;
    }

    void pos(int position) {
        if (start == -1) {
            start = position;
        } else if (curr == -1) {
            curr = position;
            mini = min(mini,curr-start);
            maxi = max(maxi,curr-start);
                   
        } else {
            prev = curr;
            curr = position;
            mini = min(mini,curr - prev);
            maxi = max(maxi,curr - start);
        }
    }

    pair<int, int> minMax() {
        
        if(mini==INT_MAX || maxi==INT_MIN) return {-1,-1};
        return {mini,maxi};
    }
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int criticalCounter = 2;
        setPos counterObj;
        int prevNode = -1;
        if(head->next->next==nullptr) return {-1,-1};

        if (head != nullptr) {
            prevNode = head->val;
            head = head->next;
        }

        while (head != nullptr && head->next != nullptr) {
            if (head->val > prevNode && head->val > head->next->val) {
                counterObj.pos(criticalCounter);
            } else if (head->val < prevNode && head->val < head->next->val) {
                counterObj.pos(criticalCounter);
            }
            prevNode = head->val;
            head = head->next;
            criticalCounter++;
        }

        auto minMaxPair = counterObj.minMax();
        return {minMaxPair.first, minMaxPair.second};
    }
};