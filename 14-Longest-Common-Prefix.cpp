class Node{
    public:
  Node *links[26];
  bool flag;
  int cp;
    Node(){
        for(int i=0;i<26;i++){
            links[i]=NULL;
        }
        flag=false;
        cp=0;
    }
};

class Trie{
private:
   Node *root;
public:
    Trie(Node *root){
      this->root=root;
    }

    void insert(string num){
        Node *node=root;
        for(int i=0;i<num.length();i++){
              if(!node->links[num[i]-'a']){
                node->links[num[i]-'a']=new Node();
              }

              node=node->links[num[i]-'a'];
              node->cp+=1;
        }
        node->flag=true;
    }
};



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Node *node=new Node();
        Trie *t=new Trie(node);
        

        for(auto &s:strs){
              t->insert(s);
        }

       int n = strs.size();
        Node *q = node;
        string ans = "";

        for(char c : strs[0]){

                  if(q->links[c-'a']->cp != n)
                        break;

                    ans += c;
                    q = q->links[c-'a'];
        }

        return ans;
    }
};