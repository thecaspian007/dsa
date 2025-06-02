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
    ListNode* reverse(ListNode* temp) {
        ListNode* curr = temp;
        ListNode* prev = nullptr;
        ListNode* forward = nullptr;

        while(curr != nullptr)
        {
            forward = curr->next;
            curr->next = prev;
            prev =curr;
            curr = forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* secondHalf = reverse(slow->next);
        ListNode* firstHalf = head;
        ListNode* temp = secondHalf;

        while(temp) {
            if(firstHalf->val != temp->val)
            {
                return false;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }
        return true;
    }
};