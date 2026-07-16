class Node{
    public:
  Node *links[2];
    Node(){
        for(int i=0;i<2;i++){
            links[i]=NULL;
        }
    }
};

class Trie{
private:
   Node *root;
public:
    Trie(Node *root){
      this->root=root;
    }

    void insert(int num){
        Node *node=root;
        //insert this number bitwise
        for(int i=31;i>=0;i--){
            //seeing if that bit of num is set or is zero
              int bit=(num >>i)&1;
              if(!node->links[bit]){
                node->links[bit]=new Node();
              }

              node=node->links[bit];
        }


    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Node *node=new Node();
        
        Trie *t=new Trie(node);
        for(auto &num:nums){
            t->insert(num);
        }
        
        
        //here same element would have:
        //XOR-->0
        //so for any num max xor we can can reach that we are cheking
        
        int maxiNum=0;
        for(auto &num:nums){
            //check for num here
            //with whom this will give a max XOR
            int val=0;
            Node *n=node;
            for(int i=31;i>=0;i--){
                  int bit=(num >>i)&1;
                if(n->links[1-bit]){//opp bit exists what we actauulay wantened
                      val=val|(1<<i);
                      n=n->links[1-bit];
                }else{
                    n=n->links[bit];
                }
            }

            if(maxiNum<=val){
                maxiNum=val;
            }
        }
        return maxiNum;
    }
};