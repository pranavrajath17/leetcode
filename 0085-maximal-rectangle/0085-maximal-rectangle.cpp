class Solution {
public:
int histogram(vector<int>& height){
    int n=height.size();
    vector<int> nsr(n);
    vector<int> nsl(n);
    stack<int> s;
   
    //nsr only
    nsr[n-1]=n;
    s.push(n-1);
    for(int i=n-2;i>=0;i--){
        int curr=height[i];
        while(!s.empty()&& height[s.top()]>=curr){
            s.pop();
        }
        if(s.empty()){
            nsr[i]=n;
        }else{
            nsr[i]=s.top();
        }
        s.push(i);
    }

while(!s.empty()){
    s.pop();
}
//nsl only
nsl[0]=-1;
s.push(0);
for(int i=1;i<n;i++){
    int curr=height[i];
    while(!s.empty()&& height[s.top()]>=curr){
        s.pop();
    }
    if(s.empty()){
        nsl[i]=-1;
    }else{
        nsl[i]=s.top();
    }
    s.push(i);
}
int maxarea=0;
for(int i=0;i<n;i++){
    //area of triangle is only form
    int ht=height[i];
    int wt=nsr[i]-nsl[i]-1;
    int area=ht *wt;
    maxarea=max(maxarea,area);
}
return maxarea;
}

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>height(m,0);
        int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]++;
                }else{
                    height[j]=0;
                }
            }
            int area=histogram(height);
            maxarea=max(maxarea,area);
        }
        return maxarea;

    }
};