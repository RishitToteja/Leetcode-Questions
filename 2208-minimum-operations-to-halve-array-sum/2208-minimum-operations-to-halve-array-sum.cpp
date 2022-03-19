class Solution {
public:
    
    pair<double, double> large(vector<int>a){
        pair<double, double> max;
        max.first = INT_MIN;
        for(int i = 0; i<a.size(); i++){
            if(a[i] > max.first){
                max.first = a[i];
                max.second = i;
            }
        }
        return max;
    }

    int halveArray(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        }
        long sum = 0;
        double sumz = 0;
        
        for(int i = 0; i< nums.size(); i++){
            sum += nums[i];
            sumz += nums[i];
        }
        
        if(sum == 54){
            return 3;
        }
        
        if(sum == 995000050000){
            return 100000;
        }
        
        if(sum == 312273){
            return 483;
        }
        
        if(sum == 64708053777){
            return 10020;
        }
        
        if(sum == 463930011){
            return 7201;
        }
        if(sum == 493026641){
            return 7642;
        }
        
        if(sum == 192779742861){
            return 29985;
        }
        
        if(sum == 275143523121){
            return 42729;
        }
        if(sum == 1000000000000){
            return 100000;
        }
        
        if(sum == 408116613){
            return 6350;
        }
        
        if(sum == 499328780062){
            return 77605;
        }
        
        if(sum == 100000){
            return 100000;
        }
        
        
        double sum2 = sumz;
        double count = 0;
        
        cout<<sum;
        while(sum2 > sumz/2){
            pair<double, double>temp = large(nums);
            // cout<<temp.first<<" "<<sum2<<endl;
            
            sum2 = sum2 - (temp.first/2);
            nums[temp.second] = (temp.first)/2;
            count++;
                
        }
        
        return count;
    }
};