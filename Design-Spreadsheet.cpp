class Spreadsheet {
public:

bool isNumber(string s){
    if(s.empty())return false;
    for(auto it:s){
        if(!isdigit(it))return false;
    }
    return true;
}

vector<vector<int>>vec;
    Spreadsheet(int rows) {
        vec.resize(26,vector<int>(rows+1,0));
    }
    
    void setCell(string cell, int value) {
        int x=stoi(cell.substr(1));
        vec[cell[0]-'A'][x]=value;
    }
    
    void resetCell(string cell) {
          int x=stoi(cell.substr(1));
        vec[cell[0]-'A'][x]=0;
    }

int getValue(string formula) {
        int n=formula.length();
       string s1="";
       string s2="";
       int i=1;
       while(formula[i]!='+'){
        s1+=formula[i];
        i++;
       }
       i++;
       while(i<n){
        s2+=formula[i];
        i++;
       }
       int x,y;
       x=isNumber(s1)?stoi(s1):vec[s1[0]-'A'][stoi(s1.substr(1))];
      y=isNumber(s2)?stoi(s2):vec[s2[0]-'A'][stoi(s2.substr(1))];
      return x+y;
    //    int x,y;
    //  cout<<s1<<" "<<s2<<endl;
    //    if(isNumber(s1)){
    //       x=stoi(s1);
    //    }else{
    //     int t=s1[0]-'A';
    //     int q=1;
    //     string s="";
    //     while(q<s1.length()){
    //        s+=s1[q];
    //        q++;
    //     }
    //     int c=stoi(s);
    //     x=vec[t][c];
    //    }

      
    //    if(isNumber(s2)){
    //       y=stoi(s2);
    //    }else{
    //    int t=s2[0]-'A';
    //     int q=1;
    //     string s="";
    //     while(q<s2.length()){
    //        s+=s2[q];
    //        q++;
    //     }
    //     int c=stoi(s);
    //     y=vec[t][c];
    //    }
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */