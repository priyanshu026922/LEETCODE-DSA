1class Node{
2   public:
3    string data;
4    Node*next;
5    Node*prev;
6    Node(string data){
7        this->data=data;
8        next=NULL;
9        prev=NULL;
10    }
11};
12
13class BrowserHistory {
14
15public:
16Node*curr;
17    BrowserHistory(string homepage) {
18        Node* newNode=new Node(homepage);
19        curr=newNode;
20    }
21    
22    void visit(string url) {
23        Node* newNode=new Node(url);
24        curr->next=newNode;
25       
26        newNode->prev=curr;
27         curr=curr->next;
28    }
29    
30    string back(int steps) {
31        while(steps>0&&curr->prev){
32           curr=curr->prev;
33            steps--;
34        }
35        return curr->data;
36    }
37    
38    string forward(int steps) {
39          while(steps>0&&curr->next){
40           curr=curr->next;
41            steps--;
42        }
43        return curr->data;
44    }
45};
46
47/**
48 * Your BrowserHistory object will be instantiated and called as such:
49 * BrowserHistory* obj = new BrowserHistory(homepage);
50 * obj->visit(url);
51 * string param_2 = obj->back(steps);
52 * string param_3 = obj->forward(steps);
53 */