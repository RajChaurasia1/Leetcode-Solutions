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
    
    
    struct cmp {
    bool operator()(
        struct ListNode* a, struct ListNode* b)
    {
        return a->val > b->val;
    }
};
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
         priority_queue<ListNode*,vector<ListNode*>, cmp>pq;
        for(int i = 0 ; i < lists.size() ; i++){
            if(lists[i] != NULL)
                pq.push(lists[i]);
        }
        
       
        
        while(!pq.empty()){
        
            auto least=pq.top();
            pq.pop();
            temp->next=least;
            temp=temp->next;
            if(least->next)          
                pq.push(least->next);
    }
    return head->next;
        
        
    }
};