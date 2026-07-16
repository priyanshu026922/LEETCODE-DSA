class Node{
public:
    Node *links[26];
    bool isLast;
    int cnt_pref;
    int cnt_word;
    Node(){
        for(int i=0;i<26;i++){
            links[i]=NULL;
        }
            cnt_pref=0;
            cnt_word=0;//how many word are there for this prefix till now
            isLast=false;
    }
};

class Trie{
private:
    Node *root;
public:
    Trie(Node *root){
        this->root=root;
    }

    void insert(string &word){
        int n=word.length();
        Node*node=root;

        for(int i=0;i<n;i++){
            if(!node->links[word[i]-'a']){
                node->links[word[i]-'a']=new Node();
                
            }
            
            node=node->links[word[i]-'a'];
            node->cnt_pref+=1;
        }
        node->isLast=true;
        node->cnt_word+=1;
    }

};

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        Node *node=new Node();
        Trie *t=new Trie(node);
       
        for(auto &it:words){
            t->insert(it);
        }


        Node*root=node;
        for(int i=0;i<pref.length();i++){
            if(!root->links[pref[i]-'a']){
                return 0;
            }
            root=root->links[pref[i]-'a'];
        }

        return root->cnt_pref;
    }
};