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
13   ListNode *solve(ListNode*temp){
14    if(temp==NULL||temp->next==NULL)return temp;
15
16    ListNode*newNode=solve(temp->next);
17    ListNode*nxt=temp->next;
18    nxt->next=temp;
19    temp->next=NULL;
20    return newNode;
21   }
22    ListNode* reverseList(ListNode* head) {
23
24        return solve(head);
25    }
26};