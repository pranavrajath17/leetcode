class Solution {
private:
vector<int> findNSE(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(n);
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        int curr=nums[i];
        while(!s.empty()&&nums[s.top()]>=curr){
            s.pop();
        }
        if(s.empty()){
            ans[i]=n;
        }else{
            ans[i]=s.top();
        }
        s.push(i);
    }
    return ans;
}
vector<int> findNGE(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(n);
    stack<int> s;
    for(int i=n-1;i>=0;i--){
        int curr=nums[i];
        while(!s.empty()&&nums[s.top()]<=curr){
            s.pop();
        }
        if(s.empty()){
            ans[i]=n;
        }else{
            ans[i]=s.top();
        }
        s.push(i);
    }
    return ans;
}
vector<int> findPSE(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(n);
    stack<int> s;
    for(int i=0;i<n;i++){
        int curr=nums[i];
        while(!s.empty()&&nums[s.top()]>curr){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }else{
            ans[i]=s.top();
        }
        s.push(i);
    }
    return ans;
}
vector<int> findPGE(vector<int>& nums){
    int n=nums.size();
    vector<int> ans(n);
    stack<int> s;
    for(int i=0;i<n;i++){
        int curr=nums[i];
        while(!s.empty()&&nums[s.top()]<curr){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }else{
            ans[i]=s.top();
        }
        s.push(i);
    }
    return ans;
}
long long SumSubarrayMins(vector<int>& nums){
    vector<int>nse=findNSE(nums);
    vector<int>pse=findPSE(nums);
    long long sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
    int left=i-pse[i];
    int right=nse[i]-i;
    long long freq=left*right*1LL;
    long long val=freq*nums[i]*1LL;
    sum=sum+val;
    }
   
return sum;
}
long long SumSubarraymaxs(vector<int>& nums){
    int n=nums.size();
    vector<int> nge=findNGE(nums);
    vector<int> pge=findPGE(nums);
    long long sum=0;
    for(int i=0;i<n;i++){
        int left=i-pge[i];
        int right=nge[i]-i;
        long long freq=left*right*1LL;
        long long val=freq*nums[i]*1LL;
        sum=sum+val;
    }
    return sum;
}
public:
    long long subArrayRanges(vector<int>& nums) {
       return  SumSubarraymaxs(nums)-SumSubarrayMins(nums);
    }
};