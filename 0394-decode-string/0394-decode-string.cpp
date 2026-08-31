class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> str;
        int num=0;
        string curr="";
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(isdigit(ch)){
                num=num*10+ch-'0';
            }else if(ch=='['){
                nums.push(num);
                str.push(curr);
                num=0;
                curr="";
            }
            else if(isalpha(ch)){
                curr+=ch;
            }
            else if(ch==']'){
                int repeat=nums.top();
                nums.pop();
                string temp="";
                for(int i=0;i<repeat;i++){
                    temp+=curr;
                }
                string previous=str.top();
                str.pop();
                curr=previous+temp;
            }
        }
        return curr;
    }
};