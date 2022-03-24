class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        
        int i = 0;
        int j = people.size() - 1;
        
        int count = 0;
        int carry = 0;
        
        while(i <=j){
            
            int s = people[i];
            int e = people[j];
            
            if(s+e <= limit){
                count++;
                i++;
                j--;
            }
            
            else{
                count++;
                j--;
            }
        }
        
        return count;
    }
};

// 1 2 2 3