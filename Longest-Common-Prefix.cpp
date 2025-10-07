struct Node{

Node*links[26];
bool flag=false;

bool containsKey(char ch){
return (links[ch-'a']!=NULL);
}
void put(char ch,Node*node){
    links[ch-'a']=node;
}
Node*get(char ch){
    return links[ch-'a'];
}
void setEnd(){
    flag=true;
}
bool getEnd(){
    return flag;
}

};

class Trie{
    private:
    Node*root;
    public:
    Trie(){
 root=new Node();
    }
   void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }


string  lcp(){
    string prefix = "";
    Node* node = root;

    while (true) {
        int count = 0;
        char ch;
        for (int i = 0; i < 26; i++) {
            if (node->links[i] != nullptr) {
                count++;
                ch = 'a' + i;
            }
        }
        if (count != 1 || node->flag) break;

        prefix += ch;
        node = node->links[ch - 'a'];
    }

    return prefix;
}

};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return "";
        Trie* t=new Trie;
        int n=strs.size();
        for(int i=0;i<n;i++){
            t->insert(strs[i]);
        }
        return t->lcp();
    }
};