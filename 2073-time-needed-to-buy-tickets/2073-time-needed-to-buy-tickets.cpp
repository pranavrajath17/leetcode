class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        int n=tickets.size();
        int tottime=0;
        for(int i=0;i<n;i++){
            q.push({i,tickets[i]});
        }
        while(!q.empty()){
         auto person=q.front();
        q.pop();
        person.second--;
        tottime++;
        if(person.first==k && person.second==0 ){
            return tottime;
        }
        if(person.second>0){
            q.push(person);
        }
       
        }
       
return tottime;
        
    }
};