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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL)
        return l2;
        if(l2==NULL)
        return l1;
        ListNode *head,*pa,*pb;
        if(l1->val<l2->val)
        {
            pa=head=l1;
            pb=l2;
        }
        else
        {
            pa=head=l2;
            pb=l1;
        }
        while(pa->next && pb)
        {
            while(pa->next && pa->next->val<=pb->val)
            pa=pa->next;
            if(pa->next==NULL)
            {
                pa->next=pb;
                return head;
            }
            else
            {
              ListNode *tmp=pb;
              pb=pa->next;
              pa->next=tmp;
            }
        }
        if(pa->next==NULL)
        pa->next=pb;
       // pa->next=pb;
        return head;
    }
};
