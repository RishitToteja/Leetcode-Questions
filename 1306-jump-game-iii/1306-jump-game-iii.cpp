class Solution {
public:
    bool f(vector<int> &v,int start,vector<bool>&b)
    {
        if(start>=v.size() || start<0)
        {
            return false;
        }
        cout<<v[start]<<"  ";
        if(v[start]==0)
        {
            return true;
        }
        int a = v[start];
        if(b[start]==true)
        {
            return false;
        }
        b[start]=true;
        bool left = f(v,start-a,b);
        bool right = f(v,start+a,b);
        return left||right;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<bool> b(arr.size(),false);
        return f(arr,start,b);
        
    }
};