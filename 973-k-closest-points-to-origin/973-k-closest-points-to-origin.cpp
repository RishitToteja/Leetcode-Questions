#include <queue>
#include <cmath>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<int>pq;
        
        vector<pair<vector<int>,int> >n;
        
        
        for(int i = 0; i<points.size(); i++){
            pair<vector<int>, int>temp;
            temp.first = points[i];
            temp.second = pow(points[i][0], 2)+pow(points[i][1], 2);
            n.push_back(temp);
            //cout<<temp.second<<endl;
           
        }
        
        for(int i = 0; i<k; i++){
            pq.push(n[i].second);
        }

        for(int i = k; i<n.size(); i++){
            if(pq.top()>n[i].second){
                pq.pop();
                pq.push(n[i].second);
                    
            }
        }
        //cout<<pq.top()<<endl;
        vector<vector<int>>ans;
        
        while(!pq.empty()){
            int min = pq.top();
            //cout<<min<<endl;
            for(int i = 0; i<n.size(); i++){
                if(n[i].second == min){
                    ans.push_back(n[i].first);
                    n[i].second = INT_MAX;
                    break;
                }
            }
            
            pq.pop();
        }
        return ans;
        
        
        
    }
};