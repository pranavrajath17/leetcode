class LFUCache {
public:
int capacity,minfreq;
unordered_map<int,pair<int,int>> keyval;// key,val,freq
unordered_map<int,list<int>> freqlist;//freq,nodes of key
unordered_map<int,list<int>::iterator>pos;//key,address
void updatefreq(int key){
    int currfreq=keyval[key].second;//denoting the frequency
    freqlist[currfreq].erase(pos[key]);
    keyval[key].second++;
     currfreq=keyval[key].second;
    freqlist[currfreq].push_back(key);
    pos[key]=--freqlist[currfreq].end();
    if(freqlist[minfreq].empty()){
        minfreq++;
    }
}
    LFUCache(int capacity) {
        this->capacity=capacity;
        minfreq=0;
    }
    
    int get(int key) {
        if(keyval.find(key)==keyval.end()){//if the key is not present
            return -1;
        }
        updatefreq(key);//uodate its frequency if it is present
        return keyval[key].first;
    }
    
    void put(int key, int value) {
        if(capacity==0){//if capacity is not given if it is zero
            return;
        }
        if(keyval.find(key)!=keyval.end()){//if that key is present then you need to update that value
           keyval[key].first=value;
            updatefreq(key);
             
            return;
        }
        if(keyval.size()==capacity){
            int delkey=freqlist[minfreq].front();
            keyval.erase(delkey);
            pos.erase(delkey);
            freqlist[minfreq].pop_front();
        }
        keyval[key]={value,1};
        freqlist[1].push_back(key);
        pos[key]=--freqlist[1].end();
        minfreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */