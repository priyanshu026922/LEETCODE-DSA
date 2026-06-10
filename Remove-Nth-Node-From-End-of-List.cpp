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
13    ListNode *reverse(ListNode*head){
14        ListNode*curr=head;
15        ListNode *prev=NULL;
16        while(curr){
17            ListNode*nxt=curr->next;
18            curr->next=prev;
19            prev=curr;
20            curr=nxt;
21        }
22        return prev;
23    }
24    ListNode* removeNthFromEnd(ListNode* head, int n) {
25        if(!head||!head->next){
26            return NULL;
27        }
28
29        ListNode*revHead=reverse(head);
30        
31         //now delete the nth node
32         ListNode *temp=revHead;
33         ListNode*prev=NULL;
34         int cnt=0;
35         while(temp){
36            ListNode*nxt=temp->next;
37
38           cnt++;
39           if(cnt==n){
40            //this is our required node
41               if(temp==revHead){
42                 revHead=revHead->next;
43                 break;
44               }else{
45                  prev->next=nxt;
46                  delete(temp);
47               }
48
49           }
50
51           prev=temp;
52           temp=nxt;
53         }
54
55         ListNode*newHead=reverse(revHead);
56         
57        return newHead;
58
59    }
60};