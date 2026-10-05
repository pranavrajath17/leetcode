class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        int ans=low;
        while(low<=high){
            int mid=(low+high)/2;
            int n=no_of_subarrays(nums,mid);
            if(n>k){
                low=mid+1;
            }else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
    int no_of_subarrays(vector<int>&nums,int mid){
            int count=1;
            int sum=0;
            for(int i=0;i<nums.size();i++){
                if(sum+nums[i]>mid){
                    sum=nums[i];
                    count++;
                }else{
                    sum+=nums[i];
                }
            }
             return count;
        }
       
};