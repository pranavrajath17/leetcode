class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int childindx=0;
        int cookieindx=0;
        int satisfiedchildren=0;
        while(childindx<g.size() && cookieindx<s.size()){
            if(s[cookieindx]>=g[childindx]){
                satisfiedchildren++;
                childindx++;
                cookieindx++;
            }else{
                cookieindx++;
            }
        }
        return satisfiedchildren;
    }
};