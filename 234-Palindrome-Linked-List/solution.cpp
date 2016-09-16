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
    // a b a; a a
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        stack<ListNode*> stk;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            stk.push(slow);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast) slow = slow->next;
        
        while(!stk.empty()){
            ListNode* cur = stk.top();
            stk.pop();
            if(cur->val != slow->val){
                return false;
            }
            slow = slow->next;
        }
        
        return true;
    }
};