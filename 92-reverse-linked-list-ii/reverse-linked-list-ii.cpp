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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);

        ListNode* leftPrev = dummy;
        ListNode* curr = head;
        for (int i = 0; i < left - 1; ++i) {
            leftPrev = curr;
            curr = curr->next;
        }

        ListNode* subListHead = curr;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;

        for (int i = 0; i < right - left + 1; ++i) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        leftPrev->next = prev;
        subListHead->next = curr;

        return dummy->next;
    }
};