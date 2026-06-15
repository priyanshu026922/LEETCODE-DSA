1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* deleteMiddle(ListNode* head) {
14        if(!head||!head->next){
15            return NULL;
16        }
17        ListNode*s=head;
18        ListNode*f=head->next;
19        while(f->next&&f->next->next){
20            s=s->next;
21            f=f->next->next;
22        }
23
24        ListNode*temp=s->next;
25        s->next=temp->next;
26
27        return head;
28    }
29};