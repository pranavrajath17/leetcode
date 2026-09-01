class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
         int n=nums.size();
        vector<int> ans(n);
       
        for(int i=2*n-1;i>=0;i--){
            int indx=i%n;
            int curr=nums[indx];
            while(!s.empty()&& curr>=s.top()){
                s.pop();
            }
            if(i<n){
                if(s.empty()){
                    ans[i]=-1;
                }else{
                    ans[i]=s.top();
                }
            }
            s.push(curr);
        }
        return ans;
    }
};