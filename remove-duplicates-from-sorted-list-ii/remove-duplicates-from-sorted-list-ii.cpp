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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* t = head;
        ListNode* p = head;
        int prev;
        while(t != NULL){
            if(t == head){
                int v = head->val;
                ListNode* x = t;
                int cnt = 0;
                while(x != NULL && x->val == v){
                    x = x->next;
                    cnt++;
                }
                if(cnt > 1)
                head = x;
            }
            else if(t != head){
                ListNode* d = t;
                int cnt = 0;
                prev = t->val;
                while(d != NULL && d->val == prev){
                    d = d->next;
                    cnt++;
                }
                if(cnt > 1){
                    p->next = d;
                    t = p;
                }
               
            }
         
            p = t;
            t = t->next;
            
        }
        
        return head;
    }
};