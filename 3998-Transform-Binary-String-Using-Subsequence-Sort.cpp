class Solution {
public:
    bool check(string &s,string &t){
        int cnt_s=0;
        int cnt_t=0;
        for(int i=t.length()-1;i>=0;i--){
             if(t[i]=='0')cnt_t++;
             if(s[i]=='0')cnt_s++;

             if(cnt_t>cnt_s)return false;
        }
        return true;
    }
    vector<bool> transformStr(string s, vector<string>& strs) {
          vector<bool>ans;

          int n=s.length();
          int cnt_0_s=0;
          int cnt_1_s=0;
          for(char ch:s){
            if(ch=='0'){
                cnt_0_s++;
            }else{
                cnt_1_s++;
            }
          }

          //checking for strs
          for(auto str:strs){
            
            int cnt_0_str=0;
            int cnt_1_str=0;
            for(auto ch:str){
                if(ch=='0'){
                    cnt_0_str++;
                }else if(ch=='1'){
                    cnt_1_str++;
                }
            }

            if(cnt_0_str>cnt_0_s||cnt_1_str>cnt_1_s){
                ans.push_back(false);
                continue;
            }

            string temp=str;
            for(int i=0;i<temp.length();i++){
                if(temp[i]=='?'){
                    if(cnt_0_str<cnt_0_s){
                       temp[i]='0';
                       cnt_0_str++;
                    }else{
                        temp[i]='1';
                        cnt_1_str++;
                    }
                }
            
            }

            if(check(s,temp)){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
          }
          return ans;
    }
};