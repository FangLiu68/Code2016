/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode* cur = head;
        ListNode* next_node = head->next;
        
        ListNode* newHead = reverseList(next_node);
        next_node->next = cur;
        cur->next = NULL;
        
        return newHead;
    }
};