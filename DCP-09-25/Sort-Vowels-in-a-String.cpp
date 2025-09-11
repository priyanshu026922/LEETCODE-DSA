class Solution {
public:
bool static cmp(pair<char,int>&v1,pair<char,int>&v2){
    if(int(v1.first)<int(v2.first)){
        return true;
    }
    return false;
}
    string sortVowels(string s) {
         int n=s.length();
         string ans=s;
         vector<pair<char,int>>vec;
         for(int i=0;i<n;i++){
               if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                vec.push_back({s[i],i});
               }
         }
         sort(begin(vec),end(vec),cmp);
       int j=0;
       int m=vec.size();
         for(int i=0;i<n&&j<m;i++){
          if(s[i]!='a'&&s[i]!='e'&&s[i]!='i'&&s[i]!='o'&&s[i]!='u'&&s[i]!='A'&&s[i]!='E'&&s[i]!='I'&&s[i]!='O'&&s[i]!='U'){
              
            ans[i]=s[i];
          }else{
             ans[i]=vec[j].first;
               j++;
          }
         }
        return ans;
    }
};