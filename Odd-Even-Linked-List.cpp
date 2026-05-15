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
13    ListNode* oddEvenList(ListNode* head) {
14        if(head==NULL||head->next==NULL){
15            return head;
16        }
17
18        ListNode*odd=head;
19        ListNode*even=head->next;
20        ListNode*evenH=head->next;
21
22        
23        while(even&&even->next){
24           odd->next=odd->next->next;
25           even->next=even->next->next;
26
27           odd=odd->next;
28           even=even->next;
29        }
30        
31        odd->next=evenH;
32
33        return head;
34
35    }
36};