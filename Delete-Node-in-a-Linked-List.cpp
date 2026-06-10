1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    void deleteNode(ListNode* node) {
12        ListNode*temp=node;
13        ListNode*prev=NULL;
14        while(temp->next){
15            ListNode*nxt=temp->next;
16            swap(nxt->val,temp->val);
17            prev=temp;
18            temp=temp->next;
19        }
20
21        prev->next=NULL;
22    }
23};