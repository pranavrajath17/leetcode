class StockSpanner {
public:
stack<int> s;
vector<int>stock;

    StockSpanner() {
        
    }
    
    int next(int price) {
        stock.push_back(price);
        int i=stock.size()-1;
         while(!s.empty() && price>=stock[s.top()]){
                s.pop();
            }
            int span;
            if(s.empty()){
                span=i+1;
            }else{
                    int prevhigh=s.top();
                    span=i-prevhigh;
            
            }
            s.push(i);
            return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */