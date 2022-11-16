class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0,b=0,c=0;
        for(int i :nums){
            if(i==0)a++;
            else if(i==1)b++;
            else c++;
        }
        int i=0;
        
        //cout<<a<<b<<c;
        if(a>0){
            for(;i<a;i++)
                nums[i]=0;
        }
        
        if(b>0){
            for(;i<(a+b);i++)
                nums[i]=1;
        }
        
        if(c>0){
            for(;i<(a+b+c);i++)
                nums[i]=2;
        }
        return ;
            
    }
};