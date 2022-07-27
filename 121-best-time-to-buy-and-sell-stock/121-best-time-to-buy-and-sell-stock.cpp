class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        pair<int,int> maximum = {0, -1}; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minimum;
        minimum.push({prices[0], 0});
        
        for(int i = 1; i<prices.size(); i++){
            
            if(prices[i]-minimum.top().first>maximum.first){
                maximum.first = prices[i]- minimum.top().first;
                maximum.second = i;

            }            
            if(prices[i]<minimum.top().first){
                minimum.push({prices[i], i});
            }
        }
        while(!minimum.empty() && minimum.top().second>maximum.second){
            minimum.pop();
            if(minimum.empty())
                return 0;
        }
        
        cout<<"Buy on: "<<minimum.top().second<<endl;
        cout<<"Sell on: "<<maximum.second<<endl;
        
        return (prices[maximum.second] - prices[minimum.top().second]);
    }
};