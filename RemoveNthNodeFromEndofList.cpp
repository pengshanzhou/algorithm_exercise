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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p=head;
        ListNode *target=head;
        for(int i=0; i<n;i++)
        {
            if(p==NULL)
            return false;
            p=p->next;
        }
        if(p==NULL)
        {
            head=head->next;
            free(target);
            target=NULL;
            return head;
        }
        while(p->next)
        {
            p=p->next;
            target=target->next;
        }
        ListNode *s=target->next;
        target->next=target->next->next;
        free(s);
        s=NULL;
        return head;
        
        
    }
};
