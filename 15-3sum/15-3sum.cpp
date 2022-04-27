class pairs{
    public:
        int a;
        int b;
        int c;
    bool isEqual(pairs P){
        bool bol;
        
        if(a == P.a){
            if(b == P.b && c == P.c){
                bol = true;
            }
            else if(b == P.c && c == P.b){
                bol = true;
            }
            else{
                bol = false;
            }
        }
        if(a == P.b){
            if(b == P.c && c == P.a){
                bol = true;
            }
            else if(b == P.a && c == P.c){
                bol = true;
            }
            else{
                bol = false;
            }
        }
        if(a == P.c){
            if(b == P.a && c == P.b){
                bol = true;
            }
            else if(b == P.b && c == P.a){
                bol = true;
            }
            else{
                bol = false;
            }
        }
        return bol;
    }
    vector<int> toVector(){
        vector<int>ans = {a, b, c};
        return ans;
    }
};
class Solution {
public:
    
    

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>finals;
        
        if(nums.size() < 3){
            return finals;
        }
        sort(nums.begin(), nums.end());

        
        vector<pairs>ans;
        
        for(int i=0; i<nums.size()-2; i++){
            int req = 0 - nums[i];
            int si = i+1;
            int ei = nums.size()-1;
            
            while(si<ei){
                int sum = nums[si] + nums[ei];
                if(sum > req){
                    ei--;
                }
                if(sum < req){
                    si++;
                }
                if(sum == req){
                    pairs p;p.a = nums[i];p.b = nums[si];p.c = nums[ei];
                    ans.push_back(p);
                    si++;
                    ei--;
                }
            }
        }
        vector<pairs>set;
        for(int i=0; i<ans.size(); i++){
            bool bol = true;
            for(int j =0; j<set.size(); j++){
                if(ans[i].isEqual(set[j])){
                    bol = false;
                }
            }
            if(bol){
                set.push_back(ans[i]);
            }
        }
        
        
        for(int i=0; i<set.size(); i++){
            finals.push_back(set[i].toVector());
        }
        
        return finals;
    }
    
    
    
};