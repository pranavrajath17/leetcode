class Solution {
public:
    bool isValid(string s) {
       stack<char> ss;
       for(int i=0;i<s.size();i++){
        char ch=s[i];
        if(ch=='('||ch=='['||ch=='{'){
            ss.push(ch);
        }else{
            if(ss.empty()){
                return false;
            }
            int top=ss.top();
            if((top=='(' && ch==')')||(top=='[' && ch==']')||(top=='{' &&ch=='}')){
                ss.pop();
            }else{
                return false;
            }
        }

       }
       return ss.empty();
       }
    

};
