class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans="";
        for(int i=0;i<n;i++){
            for(int value=1;value<=26;value++){
                int remainingk=k-value;
                int remainingpositions=n-i-1;
                //this is to check if i choose value 1 i have remaining two characters to take can i choose smaller or bigger like 2<=26<=52 this condition satisfies
                if(remainingk>=remainingpositions && remainingk<=remainingpositions*26){
                    //in ans you add 's'+value-1
                ans.push_back('a'+value-1);
                //then you will update k to recognise the program that this is the new k
                k=remainingk;
                break;
                }

            }
        }
        return ans;
    }
};