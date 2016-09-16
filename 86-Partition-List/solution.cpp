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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        ListNode dummy_small(-1);
        ListNode dummy_large(-1);
        ListNode* start_small = &dummy_small;
        ListNode* start_large = &dummy_large;
        
        ListNode* cur = head;
        while(cur){
            if(cur->val < x){
                start_small->next = cur;
                start_small = start_small->next;
            }else{
                start_large->next = cur;
                start_large = start_large->next;
            }
            cur = cur->next;
        }
        
        start_large->next = NULL;
        start_small->next = dummy_large.next;
        
        return dummy_small.next;
    }
};