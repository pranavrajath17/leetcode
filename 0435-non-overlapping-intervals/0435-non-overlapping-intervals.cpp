class Solution {
public:
static bool compare(vector<int>&p1,vector<int>&p2){
    return p1[1]<p2[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //sort based on endtime
        sort(intervals.begin(),intervals.end(),compare);
        int prevendtime=intervals[0][1];
        int ans=1;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=prevendtime){
                ans++;
                prevendtime=intervals[i][1];
            }
        }
        return intervals.size()-ans;
    }
};