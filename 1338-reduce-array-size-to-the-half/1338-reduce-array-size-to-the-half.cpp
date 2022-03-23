class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        //sort(arr.begin(), arr.end());
        
        int n = arr.size();
        
        
        int a[100001];
        
        for(int i = 0; i<=100000; i++){
            a[i] = 0;
        }
        
        
        for(int i = 0; i<arr.size(); i++){
            a[arr[i]-1] += 1;  
        }
        
        vector<int>news;
        
        for(int i = 0; i<=100000; i++){
            if(a[i] != 0){
                news.push_back(a[i]);
            }
        }
        
        
        int count = 0;
        
        sort(news.begin(), news.end());
        
        for(int i = 0; i<news.size(); i++){
            cout<<news[i]<<" ";
        }
        
        int j = news.size()-1;
        
        int carry = 0;
        if(news[j] >= n/2){
            return 1;
        }
        if(news[j-1] + news[j] >=  n/2){
            return 2;
        }
        while(carry <  n/2){
            carry += news[j];
            j--;
            count++;
        }
        
        return count;
    }
};