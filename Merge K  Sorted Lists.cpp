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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>>pq;
        for(auto it:lists)
        {
            if(it)
            {
                pq.push({it->val,it});
            }
            
        }
        ListNode *head, *cur;
        head = NULL;
        cur = NULL;
        while(!pq.empty())
        {
            ListNode* first = pq.top().second;
            pq.pop();
            if(first->next !=NULL)
                pq.push({first->next->val,first->next});
            if(head == NULL)
            {
                head = first;
                cur = first;
            }
            else 
            {
                cur->next = first;
                cur=cur->next;
            }
        }
        return head;
    }
};