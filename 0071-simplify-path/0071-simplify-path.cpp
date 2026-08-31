class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s1;
        stack<string> s2;
        string curr="";
        for(int i=0;i<=path.size();i++){
                if(i==path.size()||path[i]=='/'){
                    if(curr==".."){
                        if(!s1.empty()){
                            s1.pop();
                        }
                    }
                    else if(curr!="" && curr!="."){
                        s1.push(curr);
                    }
                    curr="";
                }
                else{
                    curr+=path[i];
                }
        }
        while(!s1.empty()){
            string top=s1.top();
            s1.pop();
            s2.push(top);
        }
        string ans="";
        while(!s2.empty()){
            string top=s2.top();
            s2.pop();
            ans+='/'+top;
        }
        if(ans==""){
            return "/";
        }
        return ans;
    }
};