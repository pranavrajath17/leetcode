class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(int i=0;i<num.size();i++){
            char digit=num[i];
            while(!s.empty() && k>0 &&s.top()>digit){
                s.pop();
                k--;
            }
            s.push(digit);
        }
        while(!s.empty()&&k>0){
            s.pop();
            k--;
        }
        if(s.empty()){
            return "0";
        }
        string res="";
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
      
        reverse(res.begin(),res.end());
        int i=0;
        while(i<res.size()&&res[i]=='0'){
            i++;
        }
        if(i==res.size()){
            return "0";
        }
        return res.substr(i);
    }
};