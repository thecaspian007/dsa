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
        if (!head || !head->next || k == 0) return head;
        
        int len = 1;
        
        ListNode* temp = head;
        ListNode* dummy = head;

        while(temp->next){
            temp = temp->next;
            len++;
        }
        temp->next = head;

        k = k % len;
        if(k == 0){
            temp->next = nullptr;
            return head;
        }
        int n = len - k - 1;

        for(int i = 0; i<n; i++){
            dummy = dummy->next;
        }
        
        ListNode* newHead = dummy->next;
        dummy->next = nullptr;

        return newHead;
    }
};