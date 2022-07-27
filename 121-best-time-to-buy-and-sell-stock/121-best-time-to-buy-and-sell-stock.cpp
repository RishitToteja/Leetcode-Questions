class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        pair<int,int> maximum = {0, -1}; 
        pair<int,int> minimum = {prices[0], 0};
        
        for(int i = 1; i<prices.size(); i++){
            
            if(prices[i]-minimum.first>maximum.first){
                maximum.first = prices[i]- minimum.first;
                maximum.second = i;
            }
                
            
            if(prices[i]<minimum.first){
                minimum.first = prices[i];
                minimum.second = i;
            }
        }
        cout<<"Buy on: "<<minimum.second<<endl;
        cout<<"Sell on: "<<maximum.second<<endl;
        
        return maximum.first;
    }
};