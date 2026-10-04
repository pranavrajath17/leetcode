class Solution {
public:
static bool compare(vector<int> &p1,vector<int> &p2){
    return p1[1]<p2[1];
}
    int findMinArrowShots(vector<vector<int>>& points) {
        //sort the endtime minimally
        sort(points.begin(),points.end(),compare);
        //taking the firstvalue and keeping it as a count
        int curendtime=points[0][1];
        int arrow=1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]>curendtime){
                arrow++;
                curendtime=points[i][1];
            }
        }
        return arrow;
    }
};