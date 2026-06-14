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
13    int findCnt(ListNode* head){
14        int c=0;
15        ListNode*temp=head;
16        while(temp){
17            c++;
18            temp=temp->next;
19        }
20        return c;
21    }
22
23    ListNode*reverse(ListNode*head){
24        ListNode*t=head;
25        ListNode*p=NULL;
26        while(t){
27            ListNode*nxt=t->next;
28
29            t->next=p;
30            p=t;
31            t=nxt;
32        }
33        return p;
34    }
35    int pairSum(ListNode* head) {
36        
37        int cnt=findCnt(head);
38        int n=cnt/2;
39
40
41        ListNode*t=head;
42        while(t){
43            n--;
44            if(n==0)break;
45
46            t=t->next;
47        }
48
49        ListNode*nxt=t->next;
50
51        t->next=NULL;
52
53        t=head;
54
55        ListNode*revHead=reverse(nxt);
56
57
58        ListNode*rev=revHead;
59
60        int maxi=INT_MIN;
61        while(rev&&t){
62            int val=rev->val+t->val;
63
64            maxi=max(maxi,val);
65
66            rev=rev->next;
67            t=t->next;
68        }
69
70        return maxi;
71
72    }
73};