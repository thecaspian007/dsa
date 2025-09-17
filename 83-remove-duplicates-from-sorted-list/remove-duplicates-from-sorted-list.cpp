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
       ListNode* temp = head;
       if(head == nullptr){
        return temp;
       }

       while(temp != nullptr) {
        if(temp->next != nullptr && temp->val == temp->next->val)
        {
            temp->next = temp->next->next;
            continue;
        }
        temp = temp->next;
       }
       return head;
    }
};