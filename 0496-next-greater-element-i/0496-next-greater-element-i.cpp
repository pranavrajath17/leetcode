class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n= nums2.size();
        stack<int>s;
        vector<int>nge(n);
        nge[n-1]=-1;
        s.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){
                int curr=nums2[i];
                while(!s.empty() && curr>=s.top()){
                    s.pop();
                }
                if(s.empty()){
                    nge[i]=-1;
                }else{
                    nge[i]=s.top();
                }
        s.push(curr);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nge[j]);
                    break;
                }
            }
        }
        return ans;


        
    }
};