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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* tail = head;
        int count = 1;
        while (tail->next) {
            tail = tail->next;
            count++;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;
        ListNode* curr = head;

        for (int i = 0; i < count; ++i) {
            if (curr->val >= x) {
                if (curr == tail) {
                    break; 
                }
                prev->next = curr->next;
                curr->next = nullptr;
                tail->next = curr;
                tail = curr;
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};