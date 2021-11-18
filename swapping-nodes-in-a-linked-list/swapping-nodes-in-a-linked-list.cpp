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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*t = head, *s = head, *f = head;
        
        while(--k)
            f = f->next;
        
        t = f;
        
        while(f->next)
            f = f->next, s = s->next;
        
        swap(t->val,s->val);
        return head; 
    }
    
};