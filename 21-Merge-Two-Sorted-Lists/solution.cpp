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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        ListNode dummy(-1);
        ListNode* start = &dummy;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                start->next = l1;
                l1 = l1->next;
            }else{
                start->next = l2;
                l2 = l2->next;
            }
            start = start->next;
        }
        
        if(l1){
            start->next = l1;
        }
        if(l2){
            start->next = l2;
        }
        
        return dummy.next;
    }
};