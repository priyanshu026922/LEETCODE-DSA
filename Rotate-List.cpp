1class Solution {
2public:
3    int findCnt(ListNode*temp){
4        int cnt=0;
5        ListNode*t=temp;
6        while(t){
7            t=t->next;
8            cnt++;
9        }
10        return cnt;
11    }
12    ListNode* rotateRight(ListNode* head, int k) {
13        if(!head||!head->next){
14            return head;
15        }
16
17        int n=findCnt(head);
18        cout<<n<<endl;
19        k=k%n;
20        if(k==0){
21            return head;
22        }
23
24        int l=n-k;
25
26        ListNode *temp=head;
27        while(temp){
28            l--;
29            if(l==0){
30                break;
31            }
32            temp=temp->next;
33        }
34       
35       ListNode*nxt=temp->next;
36
37
38       temp->next=NULL;
39       ListNode*Node=nxt;
40       while(Node->next){
41          Node=Node->next;
42       }
43
44       Node->next=head;
45
46       return nxt;
47
48
49
50    }
51};