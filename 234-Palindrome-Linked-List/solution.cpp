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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
        return true;
    }
    
    ListNode* cur = head;
    ListNode* rightHead = find_middleNode(cur);
    ListNode* reverse_rightHead = reverse_rightHalf(rightHead);
    ListNode* cur_right = reverse_rightHead;
    while(cur_right){
        if(cur->val != cur_right->val){
            return false;
        }
        cur = cur->next;
        cur_right = cur_right->next;
    }
    
    return true;

    }
    
    // find the middle node of the list, return the right half list's head node
ListNode* find_middleNode(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    // a b a; a a
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(fast){
        slow = slow->next;
    }
    
    return slow;
}

// reverse a single linked list
ListNode* reverse_rightHalf(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    ListNode* pre = NULL;
    ListNode* cur = head;
    
    while(cur){
        ListNode* next_node = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next_node;
    }
    
    return pre;
}
};