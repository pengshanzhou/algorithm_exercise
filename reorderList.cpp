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
    void reorderList(ListNode *head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)
        return ;
        int len=0;
        ListNode *p=head;
        while(p!=NULL)
        {
            p=p->next;
            len++;
        }
        p=head;
        for(int i=0;i<len/2;i++)
        {
            p=p->next;
        }
        ListNode *s=NULL,*pp=p->next;
        while(pp!=NULL)
        {
            p->next=s;
            s=p;
            p=pp;
            pp=pp->next;
        }
        p->next=s;
        s=p;
        
        p=head;
        ListNode *k=head->next;
        pp=s->next;
        
        for(int i=0;i<len/2-1;i++)
        {
            p->next=s;
            s->next=k;
            p=k;
            s=pp;
            k=k->next;
            pp=pp->next;
        }
        p->next=s;
       // s->next=k;     //这里很容易成环！！！！！！！！！
        return ;
    }
};
