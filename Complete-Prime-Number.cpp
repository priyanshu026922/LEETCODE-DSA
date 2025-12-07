1class Solution {
2public:
3bool isPrime(string x){
4    int n=stoi(x);
5    if(n<2)return false;
6    for(int i=2;i*i<=n;i++){
7        if(n%i==0)return false;
8    }
9    return true;
10}
11    bool completePrime(int num) {
12        string x=to_string(num);
13        int n=x.length();
14        for(int i=0;i<n;i++){
15            string a=x.substr(0,i+1);
16            if(!isPrime(a))return false;
17        }
18         for(int i=0;i<n;i++){
19            string a=x.substr(i,n-i+1);
20            if(!isPrime(a))return false;
21        }
22        return true;
23    }
24};