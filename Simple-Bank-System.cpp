class Bank {
public:
unordered_map<int,long long>mp;
    Bank(vector<long long>& balance) {
        int n=balance.size();
        for(int i=0;i<n;i++){
            mp[i+1]=balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
          if(mp.find(account1)!=mp.end()){
                if(mp[account1]>=money){
                   
                    if(mp.find(account2)!=mp.end()){
                         mp[account1]-=money;
                         mp[account2]+=money;
                         return true;
                         }
                }
          }
          return false;
    }
    
    bool deposit(int account, long long money) {
        if(mp.find(account)!=mp.end()){
            mp[account]+=money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
         if(mp.find(account)!=mp.end()){
            if(mp[account]>=money){
            mp[account]-=money;
            return true;
            }
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */