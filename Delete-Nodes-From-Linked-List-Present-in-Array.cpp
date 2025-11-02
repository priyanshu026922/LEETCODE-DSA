/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>s;
        for(int num:nums){
            s.insert(num);
        }
        
        while(head && s.count(head->val)){
             head=head->next;
        }
        if(!head)return NULL;

        // ListNode *newT=new ListNode(-1);
        // ListNode*h=temp;
        ListNode*temp=head;
        while(temp&&temp->next){
            if(s.count(temp->next->val)){
                temp->next=temp->next->next;
                // temp2->next=temp;
                //  temp2=temp2->next;
            }else{

            
            temp=temp->next;
            }
        }
        return head;
    }
};