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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0)
            return head;
        // Step 1: Find length and tail
        int length = 1;
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
            length++;
        }
        // Step 2: Effective rotations
        k %= length;
        if(k == 0)
            return head;
        // Step 3: Make circular list
        tail->next = head;
        // Step 4: Find new tail
        ListNode* newTail = head;
        for(int i = 1; i < length - k; i++)
            newTail = newTail->next;
        // Step 5: Break circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};