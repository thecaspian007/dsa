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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCritical = -1;
        int prevCritical = -1;
        int minDist = INT_MAX;
        int maxDist = -1;
        int index = 2;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr->next != nullptr) {
            ListNode* next = curr->next;
            bool isMax = (curr->val > prev->val && curr->val > next->val);
            bool isMin = (curr->val < prev->val && curr->val < next->val);
            if (isMax || isMin) {
                if (firstCritical == -1) {
                    firstCritical = index;
                } else {
                    minDist = min(minDist, index - prevCritical);
                    maxDist = index - firstCritical;
                }
                prevCritical = index;
            }
            prev = curr;
            curr = next;
            index++;
        }
        if (maxDist == -1)
            return {-1, -1};

        return {minDist, maxDist};
    }
};