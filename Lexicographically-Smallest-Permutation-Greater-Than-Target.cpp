class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n=s.length();

      multiset<char>ch;
       for(char x:s){
       ch.insert(x);
       }


       vector<string>ans;
       string str="";
       for(int i=0;i<n;i++){
          auto x=ch.upper_bound(target[i]);
          if(x!=ch.end()){
            char c=*x;
            string temp=str;
            temp+=c;//(common part of string)+(1st different character at any position)+(remaining part of string)
            ch.erase(x);
            for(char i:ch){
                temp+=i;
            }
            ch.insert(c);
            ans.push_back(temp);
          }
          auto nxt=ch.find(target[i]);
          if(nxt==ch.end())break;
          str+=*nxt;
          ch.erase(nxt);

       }
      if(ans.size()==0)return "";
      return *min_element(begin(ans),end(ans));






































        // queue<string>q;
        // sort(begin(s),end(s));
        // unordered_set<string>vis;
        // q.push(s);
        // vis.insert(s);
        // while(!q.empty()){
        //     string str=q.front();
        //     q.pop();

        //     if(str>target){
        //         return str;
        //     }

        //    next_permutation(str.begin(),str.end());
        //    string x=str;
        //     if(!vis.count(x)){
        //         q.push(x);
        //         vis.insert(x);
        //     }
        // }
        // return "";
    }
};