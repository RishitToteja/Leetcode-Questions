bool c(const vector<int>& b,const vector<int>& a){
    if (a[0] != b[0])
        return (a[0] < b[0]);
    else
       return (a[1] > b[1]);
}
class Solution {
public:
    vector<vector<int>> print(vector<vector<int>>a){
        vector<vector<int>>r;
        for(int i=0; i<a.size(); i++){
            if(a[i].size()!=0)
                r.push_back(a[i]);
        }
        return r;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), c);
        vector<vector<int>>ans;
        for(int i=0; i<people.size(); i++){
            ans.push_back({});
        }
        vector<vector<int>>::iterator it1;
        it1 = ans.begin();
        for(int i=0; i<people.size(); i++){
            it1 = ans.insert ( it1+people[i][1] , people[i]);
            it1 = ans.begin();
        }
        return print(ans);
        
    }
};