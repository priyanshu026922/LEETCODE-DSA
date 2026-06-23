1class Node{
2public:
3    int key;
4    int val;
5    Node*next;
6    Node*prev;
7    Node(int key,int val){
8        this->key=key;
9        this->val=val;
10        next=NULL;
11        prev=NULL;
12    }
13
14};
15
16class LRUCache {
17private:
18Node*head=new Node(-1,-1);
19Node*tail=new Node(-1,-1);
20int n;
21map<int,Node*>mp;
22
23public:
24    LRUCache(int capacity) {
25        n=capacity;
26        head->next=tail;
27        tail->prev=head;
28    }
29
30    void deleteNode(Node*res){
31        Node*prevNode=res->prev;
32        Node*nextNode=res->next;
33
34        prevNode->next=nextNode;
35        nextNode->prev=prevNode;
36    }
37
38    void addNode(Node* resNode){
39        Node*temp=head->next;
40
41        resNode->next=temp;
42        temp->prev=resNode;
43
44        head->next=resNode;
45        resNode->prev=head;
46
47    }
48
49    
50    int get(int key) {
51        if(mp.find(key)!=mp.end()){
52            Node*resNode=mp[key];
53            int v=resNode->val;
54
55            deleteNode(resNode);
56            addNode(resNode);
57            mp[key]=head->next;
58
59            return v;
60        }
61
62        return -1;
63    }
64    
65    void put(int key, int value) {
66        if(mp.find(key)!=mp.end()){
67            Node*res=mp[key];
68
69            deleteNode(res);
70            mp.erase(key);
71
72        }
73
74        if(mp.size()==n){
75            mp.erase(tail->prev->key);
76            deleteNode(tail->prev);
77        }
78        
79        Node*node=new Node(key,value);
80        addNode(node);
81
82        mp[key]=head->next;
83    }
84};
85