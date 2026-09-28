class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxcandies=0;
        for(int i=0;i<candies.size();i++){
            maxcandies=max(maxcandies,candies[i]);
            
        }
        vector<bool>ans;
        for(int i=0;i<candies.size();i++){
            int currcandies=candies[i]+extraCandies;
            if(currcandies<maxcandies){
                ans.push_back(false);
            }else{
                ans.push_back(true);
            }
        }
        return ans;
       
    }
};