class Solution {
public:
//prioritize basically on the number of units used or needed to be added to the answer
static bool compare(vector<int> &p1 ,vector<int> &p2){
    return p1[1]>p2[1];
}
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //sort according to the number of boxes so more amount of unit can be achieved
        sort(boxTypes.begin(),boxTypes.end(),compare);
        int count=0;
        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][0]<=truckSize){
                    count+=boxTypes[i][0]*boxTypes[i][1];
                    truckSize-=boxTypes[i][0];
            }else{
                count+=truckSize*boxTypes[i][1];
                truckSize=0;
                break;
            }
        }
        return count;
    }


};