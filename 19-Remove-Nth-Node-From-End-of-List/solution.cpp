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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }
        
        ListNode dummy(0);
        ListNode* start = &dummy;
        start->next = head;
        
        ListNode* slow = start;
        ListNode* fast = start;
        
        for(int i=0; i<n; ++i){
            if(fast == NULL) return NULL;
            fast = fast->next;
        }   
        
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* remove = slow->next;
        slow->next = remove->next;
        delete remove;
        remove = NULL;
        return dummy.next;
    }
};