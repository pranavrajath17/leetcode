class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char task:tasks){
            freq[task-'A']++;
        }
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
        }
        //this is the algorithm how i maintain for cooldown as well as how i operate pq
        queue<pair<int,int>>cooldown;//remaining freq,nextavailble time
        int currenttime=1;
        while(!pq.empty() || !cooldown.empty()){
            while(!cooldown.empty() && cooldown.front().second<=currenttime){
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
            if(!pq.empty()){
                int remainingfreq=pq.top();
                pq.pop();
                remainingfreq--;
            if(remainingfreq>0){
                cooldown.push({remainingfreq,currenttime+n+1});
            }

        }else{
            currenttime++;//this is for ideal time
            continue;
        }
        currenttime++;

    }
    return currenttime-1;
    }
};