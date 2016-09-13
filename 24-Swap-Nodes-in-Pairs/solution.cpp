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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        // Given 1->2->3->4, you should return the list as 2->1->4->3
        ListNode* node1 = head;
        ListNode* node2 = node1->next;
        
        ListNode* newHead = swapPairs(node2->next);
        
        node2->next = node1;
        node1->next = newHead;
        
        return node2;
    }
};